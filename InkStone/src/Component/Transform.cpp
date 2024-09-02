#include "pch.h"

#include "Transform.h"

namespace NXTN {
	Transform::Transform()
		: m_Position(0.0f), m_Rotation(0.0f, 0.0f, 0.0f, 0.0f), m_Scale(1.0f)
	{

	}

	void Transform::Move(const vec3& dist)
	{
		m_Position += dist;
	}

	void Transform::SetPosition(const float& x, const float& y, const float& z)
	{
		m_Position = vec3(x, y, z);
	}

	void Transform::SetPosition(const vec3& pos)
	{
		m_Position = pos;
	}

	void Transform::Scale(const vec3& amount)
	{
		m_Scale *= amount;
	}

	void Transform::SetScale(const float& x, const float& y, const float& z)
	{
		m_Scale = vec3(x, y, z);
	}

	void Transform::SetScale(const vec3& scale)
	{
		m_Scale = scale;
	}

	void Transform::Rotate(vec3 angle)  // Angle in degrees
	{
		Rotate(angle.x, angle.y, angle.z);
	}

	void Transform::Rotate(float x, float y, float z)  // Angle in degrees
	{
		x *= (float)CONST_PI_OVER_180 / 2.0f;
		y *= (float)CONST_PI_OVER_180 / 2.0f;
		z *= (float)CONST_PI_OVER_180 / 2.0f;

		float cosX = std::cos(x);
		float cosY = std::cos(y);
		float cosZ = std::cos(z);

		float sinX = std::sin(x);
		float sinY = std::sin(y);
		float sinZ = std::sin(z);

		Quaternion q(
			cosX * cosY * cosZ - sinX * sinY * sinZ,
			sinX * cosY * cosZ + cosX * sinY * sinZ,
			cosX * sinY * cosZ - sinX * cosY * sinZ,
			cosX * cosY * sinZ + sinX * sinY * cosZ
		);

		m_Rotation *= q;
	}

	void Transform::RotateByAxis(float angle, const vec3& axis)  // Angle in degrees
	{
		angle *= CONST_PI_OVER_180 / 2.0f;

		m_Rotation *= Quaternion(std::cos(angle), std::sin(angle) * axis);
	}

	void Transform::SetRotation(const Quaternion& rotation)
	{
		m_Rotation = rotation;
	}
}
