#pragma once
#include "pch.h"

namespace ygl
{
	template <typename ChildNode>
	class Node
	{
	protected:
		Node<ChildNode>* parent;
		std::vector<ChildNode*> children;

	public:
		Node() : parent(nullptr) {}
		virtual ~Node() {}

	public:
		void AddChild(ChildNode* node)
		{
			node->parent = this;
			children.push_back(node);
		}

		bool RemoveChild(ChildNode* node)
		{
			auto iter = std::find(children.begin(), children.end(), node);
			if (iter == children.end())
				return false;
			(*iter)->parent = nullptr;
			children.erase(iter);
			return true;
		}
	};
}