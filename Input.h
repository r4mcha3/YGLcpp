#pragma once
#include "pch.h"

namespace ygl
{
	class Input
	{
	private:
		static unsigned long long clock;
		static unordered_map<char, pair<int, unsigned long long>> keyState;
		static unordered_map<int, pair<int, unsigned long long>> specialKeyState;
		static unordered_map<int, pair<int, unsigned long long>> mouseState;
		static Vector2Int mousePosition;

	public:
		static void Poll();
		static void ProcessKeyDown(unsigned char key, int x, int y);
		static void ProcessKeyUp(unsigned char key, int x, int y);
		static void ProcessSpecialKeyDown(int key, int x, int y);
		static void ProcessSpecialKeyUp(int key, int x, int y);
		static void ProcessMouse(int button, int state, int x, int y);
		static void ProcessMouseMove(int x, int y);

	public:
		static bool GetKey(char key);
		static bool GetKey(int specialKey);
		static bool GetKeyDown(char key);
		static bool GetKeyDown(int specialKey);
		static bool GetKeyUp(char key);
		static bool GetKeyUp(int specialKey);
		static bool GetMouse(int button);
		static bool GetMouseDown(int button);
		static bool GetMouseUp(int button);
		static Vector2 MousePosition();
	};
}