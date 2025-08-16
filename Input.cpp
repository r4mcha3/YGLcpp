#include "pch.h"
#include "Input.h"

namespace ygl
{
	unsigned long long Input::clock = 0ULL;
	unordered_map<char, pair<int, unsigned long long>> Input::keyState;
	unordered_map<int, pair<int, unsigned long long>> Input::specialKeyState;
	unordered_map<int, pair<int, unsigned long long>> Input::mouseState;
	Vector2Int Input::mousePosition;

	void Input::Poll()
	{
		Input::clock++;
	}

	void Input::ProcessKeyDown(unsigned char key, int x, int y)
	{
		key = toupper(key);
		Input::keyState[key] = make_pair(GLUT_DOWN, Input::clock);
	}

	void Input::ProcessKeyUp(unsigned char key, int x, int y)
	{
		key = toupper(key);
		Input::keyState[key] = make_pair(GLUT_UP, Input::clock);
	}

	void Input::ProcessSpecialKeyDown(int key, int x, int y)
	{
		Input::specialKeyState[key] = make_pair(GLUT_DOWN, Input::clock);
	}

	void Input::ProcessSpecialKeyUp(int key, int x, int y)
	{
		Input::specialKeyState[key] = make_pair(GLUT_UP, Input::clock);
	}

	void Input::ProcessMouse(int button, int state, int x, int y)
	{
		Input::mouseState[button] = make_pair(state, Input::clock);
		Input::mousePosition = Vector2Int(x, y);
	}

	void Input::ProcessMouseMove(int x, int y)
	{
		Input::mousePosition = Vector2Int(x, y);
	}

	bool Input::GetKey(char key)
	{
		key = toupper(key);
		if (!Input::keyState.contains(key))
			return false;
		return Input::keyState[key].first == GLUT_DOWN;
	}

	bool Input::GetKey(int specialKey)
	{
		if (!Input::specialKeyState.contains(specialKey))
			return false;
		return Input::specialKeyState[specialKey].first == GLUT_DOWN;
	}

	bool Input::GetKeyDown(char key)
	{
		key = toupper(key);
		if (!Input::keyState.contains(key))
			return false;
		auto& pair = Input::keyState[key];
		return pair.first == GLUT_DOWN && pair.second == Input::clock;
	}

	bool Input::GetKeyDown(int specialKey)
	{
		if (!Input::specialKeyState.contains(specialKey))
			return false;
		auto& pair = Input::specialKeyState[specialKey];
		return pair.first == GLUT_DOWN && pair.second == Input::clock;
	}

	bool Input::GetKeyUp(char key)
	{
		key = toupper(key);
		if (!Input::keyState.contains(key))
			return false;
		auto& pair = Input::keyState[key];
		return pair.first == GLUT_UP && pair.second == Input::clock;
	}

	bool Input::GetKeyUp(int specialKey)
	{
		if (!Input::specialKeyState.contains(specialKey))
			return false;
		auto& pair = Input::specialKeyState[specialKey];
		return pair.first == GLUT_UP && pair.second == Input::clock;
	}

	bool Input::GetMouse(int button)
	{
		if (!Input::mouseState.contains(button))
			return false;
		return Input::mouseState[button].first == GLUT_DOWN;
	}

	bool Input::GetMouseDown(int button)
	{
		if (!Input::mouseState.contains(button))
			return false;
		auto& pair = Input::mouseState[button];
		return pair.first == GLUT_DOWN && pair.second == Input::clock;
	}

	bool Input::GetMouseUp(int button)
	{
		if (!Input::mouseState.contains(button))
			return false;
		auto& pair = Input::mouseState[button];
		return pair.first == GLUT_UP && pair.second == Input::clock;
	}

	Vector2 Input::MousePosition()
	{
		return Input::mousePosition;
	}
}