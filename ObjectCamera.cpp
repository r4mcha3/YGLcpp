#include "pch.h"
#include "Shader.h"
#include "ObjectCamera.h"

namespace ygl
{
    ObjectCamera::ObjectCamera()
    {
        viewportX = 0;
        viewportY = 0;
        viewportWidth = 0;
        viewportHeight = 0;
    }

    ObjectCamera::~ObjectCamera()
    {

    }

    Matrix4x4 ObjectCamera::ViewMatrix()
    {
        return glm::inverse(matrixTRSLocal);
    }

    Matrix4x4 ObjectCamera::ProjMatrix()
    {
        return Matrix4x4();
    }

    void ObjectCamera::BeginDraw()
    {
        GLint vp[4];
        glGetIntegerv(GL_VIEWPORT, vp);
        viewportX = vp[0];
        viewportY = vp[1];
        viewportWidth = vp[2];
        viewportHeight = vp[3];

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        GlobalUniformBlock block;
        block.view_Transform = ViewMatrix();
        block.proj_Transform = ProjMatrix();
        Shader::SetGlobalUBO(block);
    }
}