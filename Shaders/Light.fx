#ifndef _LIGHT_FX_
#define _LIGHT_FX_

#include "Global.fx"

// struct 
// color�� ����..

struct LightDesc
{
    float4 ambient;
    float4 diffuse;
    float4 specular;
    float4 emmisive;
    float3 direction;
    float padding;// 16����Ʈ�� ��Ű�� ����
};

struct MaterialDesc
{
    float4 ambient;
    float4 diffuse;
    float4 specular;
    float4 emmisive;
};

//const buffer

cbuffer LightBuffer
{
    LightDesc GlobalLight;
};
cbuffer MaterialBuffer
{
    MaterialDesc Material;
};// ������ ����: ���� ����� �ᱹ���� �ϳ��� �۷ι� constantbuff�� ��޵Ǵµ� �Ź� ��޵Ǵ°Ͱ� 1ȸ���� ���� ��������� ����.

//SRV


Texture2D DiffuseMap;
Texture2D SpecularMap;
Texture2D NormalMap;

// fucntion
float4 ComputeLight(float3 normal, float2 uv, float3 worldPosition)
{
    
    float4 ambientColor = 0;
    float4 diffuseColor = 0;
    float4 specularColor = 0;
    float4 emissiveColor = 0;
    
    //ambient
    
    //diffuse
    
    //specular
    
    //emissive
}


#endif
