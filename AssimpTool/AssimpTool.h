#pragma once

#include "IExecute.h"

class AssimpTool : public IExecute
{
	// IExecute��(��) ���� ��ӵ�
	void Init() override;
	void Update() override;
	void Render() override;
};

