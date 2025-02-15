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
    {
        float4 color = GlobalLight.ambient * Material.ambient;
        ambientColor = DiffuseMap.Sample(LinearSampler, uv)*color;

      
    
    }
    
    //diffuse
    {
        float4 color = DiffuseMap.Sample(LinearSampler, uv);
    
        float value = dot(-GlobalLight.direction, normalize(normal));
        diffuseColor = color * value * GlobalLight.diffuse * Material.diffuse;
     
    }
    //specular
    {
        float3 R = GlobalLight.direction- (2 * normal * dot(GlobalLight.direction, normal));
        R = normalize(R);
        
    //������ ����� ��Į���̱� ������ �ٽ� ���⺤�͸� ���������.
        float3 cameraPosition = CameraPosition();
        float3 E = normalize(cameraPosition - worldPosition); // ��� - �� 
    
        float value = saturate(dot(R, E)); // clamp (0~1)
    
        float specular = pow(value, 10); // ����   
    
        specularColor = GlobalLight.specular * Material.specular * specular;
    

        
    }
    //emissive
    {
        float3 cameraPosition = CameraPosition();
        float3 E = cameraPosition - worldPosition;
        float value = saturate(dot(E, normal));
        float emissive = 1.0f - value;
    
        emissive = smoothstep(0.0f, 1.0f, emissive);
        emissive = pow(emissive, 2);
        emissiveColor = GlobalLight.emmisive* Material.emmisive * emissive;
        
        
        
        
    }
    
    
    return ambientColor + diffuseColor + specularColor + emissiveColor;
}


#endif
