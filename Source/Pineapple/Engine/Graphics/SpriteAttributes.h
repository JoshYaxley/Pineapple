/*------------------------------------------------------------------------------
  Pineapple Game Engine - Copyright (c) 2011-2017 Adam Yaxley
  This software is licensed under the Zlib license (see license.txt for details)
------------------------------------------------------------------------------*/

#pragma once

#include <Pineapple/Engine/Container/Vect2.h>
#include <Pineapple/Engine/Graphics/Colour.h>
#include <Pineapple/Engine/Util/Format.h>

namespace pa
{
	class SpriteAttributes
	{
	public:
		SpriteAttributes(const Vect2<int>& size);

		// Attributes
		const Vect2<int>& getSize() const;

		PA_FORMAT_VECTOR_REAL(Position, m_position)
		PA_FORMAT_VECTOR_REAL(Origin, m_origin)
		PA_FORMAT_VECTOR_REAL(Scale, m_scale)

		void setScale(float scale);

		void setRotation(float radians);
		float getRotation() const;

		void setRotationDegrees(float degrees);
		float getRotationDegrees() const;

		void setColour(const Colour& colour);
		Colour& getColour();
		const Colour& getColour() const;

	protected:
		void setSize(const Vect2<int>& size);

	private:
		// Size
		Vect2<int> m_size;

		// Rotation clockwise in radians
		float m_rotation;

		// Colour
		Colour m_colour;
	};
}