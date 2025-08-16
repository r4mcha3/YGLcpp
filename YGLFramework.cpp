#include "pch.h"
#include "YGLFramework.h"

namespace ygl
{
	std::string YGLFramework::applicationTitle = "YGLcpp Application";
	Scene* YGLFramework::currentScene = nullptr;
	void (*YGLFramework::updateCallback)() = nullptr;

	void YGLFramework::Initialize(int argc, char** argv)
	{
		glutInit(&argc, argv);

		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
		glutInitWindowPosition(100, 100);
		glutInitWindowSize(640, 480);

		glutCreateWindow(applicationTitle.c_str());

		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
		{
			std::cerr << "Unable to initialize GLEW" << std::endl;
			exit(EXIT_FAILURE);
		}
		else
			std::cout << "GLEW Initialization" << std::endl;

		Shader::CreateGlobalUBO();

		glfwWindowHint(GLFW_SAMPLES, 8);
		glEnable(GL_MULTISAMPLE);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);

		glutIdleFunc(Update);
		glutDisplayFunc(DrawScene);
		glutReshapeFunc(Reshape);

		glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
		glutKeyboardFunc(Input::ProcessKeyDown);
		glutKeyboardUpFunc(Input::ProcessKeyUp);
		glutSpecialFunc(Input::ProcessSpecialKeyDown);
		glutSpecialUpFunc(Input::ProcessSpecialKeyUp);
		glutMouseFunc(Input::ProcessMouse);
		glutMotionFunc(Input::ProcessMouseMove);
	}

	void YGLFramework::BeginUpdateLoop()
	{
		glutMainLoop();
	}

	void YGLFramework::SetUpdateHandler(void (*callback)())
	{
		updateCallback = callback;
	}

	void YGLFramework::SwitchScene(Scene* scene)
	{
		currentScene = scene;
	}

	void YGLFramework::Update()
	{
#ifdef _DEBUG
		constexpr int REFRESH_RATE = 20;
		static int frameCount = 0;
		static std::chrono::steady_clock timer;
		static std::chrono::steady_clock::time_point lc;
		std::chrono::steady_clock::time_point c = timer.now();
		double delta = std::chrono::duration_cast<std::chrono::duration<double>>(c - lc).count();
		if (delta * REFRESH_RATE > 1.0)
		{
			int fps = (int)round(1.0 / delta * frameCount);
			glutSetWindowTitle((applicationTitle + std::format(" @ {} FPS", fps)).c_str());
			frameCount = 0;
			lc = c;
		}
		frameCount += 1;
#endif

		if (YGLFramework::updateCallback != nullptr)
			YGLFramework::updateCallback();
		Input::Poll();

		glutPostRedisplay();
	}

	void YGLFramework::DrawScene()
	{
		if (currentScene != nullptr)
			currentScene->Redraw();

		glutSwapBuffers();
	}

	void YGLFramework::Reshape(int x, int y)
	{
		glViewport(0, 0, x, y);
	}
}