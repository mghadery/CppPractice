// Part01Core.h : Include file for standard system include files,
// or project specific include files.

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#pragma once


namespace linked_list {
	template <typename T>
	struct LinkedNode
	{
		LinkedNode(T data) :data{ data }, next{ nullptr }, previous{ nullptr } {}
		void InsertAfter(LinkedNode* linkedNode)
		{
			if (next)
				next->previous = linkedNode;

			linkedNode->next = next;
			linkedNode->previous = this;

			next = linkedNode;
		}
		void InsertBefore(LinkedNode* linkedNode)
		{
			if (previous)
				previous->next = linkedNode;
			
			linkedNode->next = this;
			linkedNode->previous = previous;

			previous = linkedNode;
		}
		LinkedNode* Next()
		{
			return next;
		}
		LinkedNode* Previous()
		{
			return previous;
		}
		T& GetData()
		{
			return data;
		}
	private:
		LinkedNode* next;
		LinkedNode* previous;
		T data;
	};
}

// TODO: Reference additional headers your program requires here.
#endif