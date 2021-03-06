/*------------------------------------------------------------------------------
  Pineapple Game Engine - Copyright (c) 2011-2017 Adam Yaxley
  This software is licensed under the Zlib license (see license.txt for details)
------------------------------------------------------------------------------*/

#pragma once

#include <list>

namespace pa
{
	class Dependency
	{
	public:
		Dependency() = default;
		~Dependency() = default;
		Dependency(const Dependency& copy) = delete;
		Dependency(Dependency&& move) = delete;
		Dependency& operator=(const Dependency& assignment) = delete;
		Dependency& operator=(Dependency&& assignment) = delete;

		using Handle = std::list<Dependency*>::const_iterator;

		void notifyDependency(Dependency* parent);

		Handle addChildDependency(Dependency* child);

		void removeChildDependency(Handle& childNode);

		void notifyChildDependencies();

	protected:
		virtual void onDependencyNotify(Dependency* parent)
		{
		}

	private:

		std::list<Dependency*> m_dependencies;
	};
}
