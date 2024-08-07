#include "pch.h"

#include "Matrix.h"

namespace NXTN {
	mat3::mat3()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				m_Mat[i][j] = 0.0f;
			}
		}
	}

	mat3::mat3(float a)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				m_Mat[i][j] = 0.0f;
			}
		}

		m_Mat[0][0] = a;
		m_Mat[1][1] = a;
		m_Mat[2][2] = a;
	}

	mat3::mat3(
		const float& m00, const float& m01, const float& m02,
		const float& m10, const float& m11, const float& m12,
		const float& m20, const float& m21, const float& m22
	)
	{
		m_Mat[0][0] = m00;
		m_Mat[0][1] = m01;
		m_Mat[0][2] = m02;
		m_Mat[1][0] = m10;
		m_Mat[1][1] = m11;
		m_Mat[1][2] = m12;
		m_Mat[2][0] = m20;
		m_Mat[2][1] = m21;
		m_Mat[2][2] = m22;
	}

	mat3::mat3(mat4 m)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				m_Mat[i][j] = m[i][j];
			}
		}
	}

	mat3 Transpose(const mat3& m)
	{
		mat3 res;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				res[i][j] = m[j][i];
			}
		}

		return res;
	}

	std::string mat3::ToString()
	{
		std::stringstream ss;
		ss.precision(2);
		ss << "[[" << m_Mat[0][0] << "  " << m_Mat[0][1] << "  " << m_Mat[0][2] << "]\n";
		ss << " [" << m_Mat[1][0] << "  " << m_Mat[1][1] << "  " << m_Mat[1][2] << "]\n";
		ss << " [" << m_Mat[2][0] << "  " << m_Mat[2][1] << "  " << m_Mat[2][2] << "]]";
		const std::string s = ss.str();
		return s;
	}

	mat4::mat4()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				m_Mat[i][j] = 0.0f;
			}
		}
	}

	mat4::mat4(const float& a)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				m_Mat[i][j] = 0.0f;
			}
		}
		m_Mat[0][0] = a;
		m_Mat[1][1] = a;
		m_Mat[2][2] = a;
		m_Mat[3][3] = a;
	}

	mat4::mat4(
		const float& m00, const float& m01, const float& m02, const float& m03,
		const float& m10, const float& m11, const float& m12, const float& m13,
		const float& m20, const float& m21, const float& m22, const float& m23,
		const float& m30, const float& m31, const float& m32, const float& m33
	)
	{
		m_Mat[0][0] = m00;
		m_Mat[0][1] = m01;
		m_Mat[0][2] = m02;
		m_Mat[0][3] = m03;
		m_Mat[1][0] = m10;
		m_Mat[1][1] = m11;
		m_Mat[1][2] = m12;
		m_Mat[1][3] = m13;
		m_Mat[2][0] = m20;
		m_Mat[2][1] = m21;
		m_Mat[2][2] = m22;
		m_Mat[2][3] = m23;
		m_Mat[3][0] = m30;
		m_Mat[3][1] = m31;
		m_Mat[3][2] = m32;
		m_Mat[3][3] = m33;
	}

	mat4 Transpose(const mat4& m)
	{
		mat4 res;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				res[i][j] = m[j][i];
			}
		}

		return res;
	}

	std::string mat4::ToString()
	{
		std::stringstream ss;
		ss.precision(2);
		ss << "[[" << m_Mat[0][0] << "  " << m_Mat[0][1] << "  " << m_Mat[0][2] << "  " << m_Mat[0][3] << "]\n";
		ss << " [" << m_Mat[1][0] << "  " << m_Mat[1][1] << "  " << m_Mat[1][2] << "  " << m_Mat[1][3] << "]\n";
		ss << " [" << m_Mat[2][0] << "  " << m_Mat[2][1] << "  " << m_Mat[2][2] << "  " << m_Mat[2][3] << "]\n";
		ss << " [" << m_Mat[3][0] << "  " << m_Mat[3][1] << "  " << m_Mat[3][2] << "  " << m_Mat[3][3] << "]]";
		const std::string s = ss.str();
		return s;
	}

	mat4 TranslateMat(vec3 translation)
	{
		mat4 m(1.0f);
		m[0][3] = translation.x;
		m[1][3] = translation.y;
		m[2][3] = translation.z;
		return m;
	}

	mat4 TranslateMat(mat4 m, vec3 translation)
	{
		m[0][3] += translation.x;
		m[1][3] += translation.y;
		m[2][3] += translation.z;
		return m;
	}

	mat4 TranslateMat(vec4 translation)
	{
		mat4 m;
		m[0][3] = translation.x;
		m[1][3] = translation.y;
		m[2][3] = translation.z;
		m[3][3] = translation.w;
		return m;
	}

	mat4 TranslateMat(mat4 m, vec4 translation)
	{
		m[0][3] += translation.x;
		m[1][3] += translation.y;
		m[2][3] += translation.z;
		m[3][3] += translation.w;
		return m;
	}

	mat4 RotateMat(vec3 angles)
	{
		angles *= 0.01745329;
		mat4 rotX(1.0f);
		float sinTheta = sin(angles.x);
		float cosTheta = cos(angles.x);
		rotX[1][1] = cosTheta;
		rotX[1][2] = sinTheta;
		rotX[2][1] = -sinTheta;
		rotX[2][2] = cosTheta;

		mat4 rotY(1.0f);
		sinTheta = sin(angles.y);
		cosTheta = cos(angles.y);
		rotY[0][0] = cosTheta;
		rotY[0][2] = -sinTheta;
		rotY[2][0] = sinTheta;
		rotY[2][2] = cosTheta;

		mat4 rotZ(1.0f);
		sinTheta = sin(angles.z);
		cosTheta = cos(angles.z);
		rotZ[0][0] = cosTheta;
		rotZ[0][1] = sinTheta;
		rotZ[1][0] = -sinTheta;
		rotZ[1][1] = cosTheta;

		return mul(rotX, mul(rotY, rotZ));
	}

	mat4 ScaleMat(vec3 scales)
	{
		mat4 m(1.0f);
		m[0][0] = scales.x;
		m[1][1] = scales.y;
		m[2][2] = scales.z;
		return m;
	}

	vec4 mul(mat4 mat, vec4 vec)
	{
		vec4 res;
		res.x = mat[0][0] * vec.x + mat[0][1] * vec.y + mat[0][2] * vec.z + mat[0][3] * vec.w;
		res.y = mat[1][0] * vec.x + mat[1][1] * vec.y + mat[1][2] * vec.z + mat[1][3] * vec.w;
		res.z = mat[2][0] * vec.x + mat[2][1] * vec.y + mat[2][2] * vec.z + mat[2][3] * vec.w;
		res.w = mat[3][0] * vec.x + mat[3][1] * vec.y + mat[3][2] * vec.z + mat[3][3] * vec.w;
		return res;
	}

	mat4 mul(mat4 m1, mat4 m2)
	{
		mat4 res;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
					res[i][j] += m1[i][k] * m2[k][j];
			}
		}
		return res;
	}

	std::ostream& operator<<(std::ostream& ostr, mat3& m)
	{
		ostr << "[[" << m[0][0] << "  " << m[0][1] << "  " << m[0][2] << "]\n";
		ostr << " [" << m[1][0] << "  " << m[1][1] << "  " << m[1][2] << "]\n";
		ostr << " [" << m[2][0] << "  " << m[2][1] << "  " << m[2][2] << "]]";
		return ostr;
	}

	std::ostream& operator<<(std::ostream& ostr, mat4& m)
	{
		ostr << "[[" << m[0][0] << "  " << m[0][1] << "  " << m[0][2] << "  " << m[0][3] << "]\n";
		ostr << " [" << m[1][0] << "  " << m[1][1] << "  " << m[1][2] << "  " << m[1][3] << "]\n";
		ostr << " [" << m[2][0] << "  " << m[2][1] << "  " << m[2][2] << "  " << m[2][3] << "]\n";
		ostr << " [" << m[3][0] << "  " << m[3][1] << "  " << m[3][2] << "  " << m[3][3] << "]]";
		return ostr;
	}
}