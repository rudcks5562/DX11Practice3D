#include "pch.h"
#include "GeometryHelper.h"
#include "Camera.h"
#include "GameObject.h"
#include "CameraScript.h"
#include "MeshRenderer.h"
#include "Mesh.h"
#include "Material.h"
#include "Model.h"
#include "ModelRenderer.h"
#include "ModelAnimator.h"
#include "InstancingDemo.h"

void InstancingDemo::Init()
{
	RESOURCES->Init();
	_shader = make_shared<Shader>(L"InstancingDemo.fx");
	_camera = make_shared<GameObject>();
	_camera->GetOrAddTransform()->SetPosition(Vec3{ 0.f, 0.f, -5.f });
	_camera->AddComponent(make_shared<Camera>());
	_camera->AddComponent(make_shared<CameraScript>());

	// Material
	{
		shared_ptr<Material> material = make_shared<Material>();
		material->SetShader(_shader);
		auto texture = RESOURCES->Load<Texture>(L"Veigar", L"..\\Resources\\Textures\\veigar.jpg");
		material->SetDiffuseMap(texture);
		MaterialDesc& desc = material->GetMaterialDesc();
		desc.ambient = Vec4(1.f);
		desc.diffuse = Vec4(1.f);
		desc.specular = Vec4(1.f);
		RESOURCES->Add(L"Veigar", material);

		//instance
		_material = material;

	}
	for (int32 i = 0; i < 100; i++) {
		auto obj = make_shared<GameObject>();
		obj->GetOrAddTransform()->SetPosition(Vec3(rand() % 10, 0, rand() % 10));
		obj->AddComponent(make_shared<MeshRenderer>());

		{

			obj->GetMeshRenderer()->SetMaterial(RESOURCES->Get<Material>(L"Veigar"));
		}
		{
			auto mesh = RESOURCES->Get<Mesh>(L"Sphere");
			obj->GetMeshRenderer()->SetMesh(mesh);
			//instance
			_mesh = mesh;

		}
		_objs.push_back(obj);
	}



	RENDER->Init(_shader);

	//instance
	_instanceBuffer = make_shared<VertexBuffer>();
	 

	for (auto& obj : _objs) {
		Matrix world = obj->GetTransform()->GetWorldMatrix();
		_worlds.push_back(world);

	}
	_instanceBuffer->Create(_worlds,1);
}

void InstancingDemo::Update()
{
	_camera->Update();
	RENDER->Update();
	{
		LightDesc lightDesc;
		lightDesc.ambient = Vec4(0.4f);
		lightDesc.diffuse = Vec4(1.f);
		lightDesc.specular = Vec4(0.1f);
		lightDesc.direction = Vec3(1.f, 0.f, 1.f);
		RENDER->PushLightData(lightDesc);
	}
	//for (auto& obj : _objs) {
	//	obj->Update();
	//}
	_material->Update();
	//auto world = GetTransform()->GetWorldMatrix();
	//RENDER->PushTransformData(TransformDesc{ world });

	//_shader->GetMatrix("World")->SetMatrix((float*)&world);

	_mesh->GetVertexBuffer()->PushData();
	_instanceBuffer->PushData(); 
	_mesh->GetIndexBuffer()->PushData();


	_shader->DrawIndexedInstanced(0, 0, _mesh->GetIndexBuffer()->GetCount(), _objs.size());
}

void InstancingDemo::Render()
{
}
