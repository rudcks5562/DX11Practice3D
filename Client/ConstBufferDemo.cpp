#include "pch.h"
#include "ConstBufferDemo.h"
#include "GeometryHelper.h"

void ConstBufferDemo::Init()
{
	_shader = make_shared<Shader>(L"ConstBuffer.fx");

	_geometry = make_shared<Geometry<VertexColorData>>();
	GeometryHelper::CreateQuad(_geometry, Color(1.f, 0.f, 0.f, 1.f));


	// 쉐이더 경로 상대경로 아닌 깔끔히.

	_vertexBuffer = make_shared<VertexBuffer>();
	_vertexBuffer->Create(_geometry->GetVertices());

	_indexBuffer = make_shared<IndexBuffer>();
	_indexBuffer->Create(_geometry->GetIndices());

	//geo = 정점 데이터 (구조체) 를 벡터로 들고있음
	// geohelp: 실제로 그리는데 보조하는 클래스.
}

void ConstBufferDemo::Update()
{
	float dt = TIME->GetDeltaTime();
	if (INPUT->GetButton(KEY_TYPE::A)) {
		_translation.x -= 3.f*dt;
	}
	else if (INPUT->GetButton(KEY_TYPE::D)) {
		_translation.x += 3.f * dt;
	}
	else if (INPUT->GetButton(KEY_TYPE::W)) {
		_translation.y += 3.f * dt;
	}
	else if (INPUT->GetButton(KEY_TYPE::S)) {
		_translation.y -= 3.f * dt;
	}
	_world = Matrix::CreateTranslation(_translation);


}

void ConstBufferDemo::Render()
{

	_shader->GetMatrix("World")->SetMatrix((float*)&_world);
	_shader->GetMatrix("View")->SetMatrix((float*)&_view);
	_shader->GetMatrix("Projection")->SetMatrix((float*)&_projection);



	uint32 stride = _vertexBuffer->GetStride();
	uint32 offset = _vertexBuffer->GetOffset();


	DC->IASetVertexBuffers(0,1, _vertexBuffer->GetComPtr().GetAddressOf(),&stride,&offset);

	DC->IASetIndexBuffer(_indexBuffer->GetComPtr().Get(), DXGI_FORMAT_R32_UINT, 0);


	//_shader->Draw(0, 1, 3);
	_shader->DrawIndexed(0, 0, _indexBuffer->GetCount(), 0, 0);

}
