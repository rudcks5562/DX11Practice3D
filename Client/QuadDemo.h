#pragma once

#include "IExecute.h"
#include "Geometry.h"
class QuadDemo : public IExecute
{

public:

	// IExecute��(��) ���� ��ӵ�
	void Init() override;

	void Update() override;

	void Render() override;

	shared_ptr<Shader> _shader;
	//vector<VertexData> _vertices;
	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;

	shared_ptr<Geometry<VertexColorData>> _geometry;

};

