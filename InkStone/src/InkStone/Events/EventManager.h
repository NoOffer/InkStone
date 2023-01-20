#pragma once

#include "Event.h"

namespace InkStone
{
	// Dispatcher for a specific EventType
	template<typename T>
	struct EventDispatcher
	{
		EventDispatcher(std::function<T(void)> d, EventDispatcher<T>* n)
			: dispatcher(d), next(n)
		{
		}

		std::function<T(void)> dispatcher;
		EventDispatcher<T>* next;
	};

	// EventDispatcher linked list
	template<typename T>
	class EventDispatcherLL
	{
	public:
		EventDispatcherLL()
		{
			m_Head = NULL;
		}

		void Distpatch(T event)
		{
			EventDispatcher<T>* tempPtr = head;
			while (tempPtr) {
				tempPtr->dispatcher(event);
				tempPtr = tempPtr->dispatcher;
			}
		}

		void Push(std::function<T(void)> dispatcherFn)
		{
			m_Head = &(EventDispatcher<T>(dispatcherFn, m_Head));
		}

	private:
		EventDispatcher<T>* m_Head;
	};

	// Global event manager
	class EventManager
	{
	public:
		// Singleton
		static EventManager& getInstance()
		{
			static EventManager instance;
			return instance;
		}

		template<typename T>
		void PushCallback(std::function<T(void)> callback)
		{
			m_Dispatchers[T.GetType()].Push(callback);
		}

		template<typename T>
		void Dispatch(T event);

	private:
		EventManager();
		~EventManager() {}

	private:
		static std::vector<EventDispatcherLL<Event>> m_Dispatchers;
	};
}