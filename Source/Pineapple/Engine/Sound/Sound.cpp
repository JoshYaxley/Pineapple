/*------------------------------------------------------------------------------
  Pineapple Game Engine - Copyright (c) 2011-2017 Adam Yaxley
  This software is licensed under the Zlib license (see license.txt for details)
------------------------------------------------------------------------------*/

#include <Pineapple/Engine/Sound/Effect.h>
#include <Pineapple/Engine/Sound/Music.h>
#include <Pineapple/Engine/Sound/Sound.h>

pa::Sound::~Sound()
{
}

pa::ResourceManager& pa::Sound::getResourceManager()
{
	return m_resourceManager;
}

std::shared_ptr<pa::Effect> pa::Sound::createEffect(const char* path)
{
	auto effect = createNativeEffect(path);
	m_resourceManager.add(effect);
	return effect;
}

std::shared_ptr<pa::Music> pa::Sound::createMusic(const char* path)
{
	auto music = createNativeMusic(*this, path);
	m_resourceManager.add(music);
	return music;
}

void pa::Sound::pauseMusic()
{
	for (auto&& music : m_musicList)
	{
		music->pause();
	}
}

void pa::Sound::resumeMusic()
{
	for (auto&& music : m_musicList)
	{
		music->resume();
	}
}

void pa::Sound::setMusicEnabled(bool enabled)
{
	m_musicEnabled = enabled;

	if (m_musicEnabled)
	{
		resumeMusic();
	}
	else
	{
		pauseMusic();
	}
}

void pa::Sound::setEffectEnabled(bool enabled)
{
	m_effectEnabled = enabled;
}

bool pa::Sound::getMusicEnabled()
{
	return m_musicEnabled;
}

bool pa::Sound::getEffectEnabled()
{
	return m_effectEnabled;
}

pa::Sound::Handle pa::Sound::registerMusic(pa::Music* music)
{
	return m_musicList.insert(m_musicList.cend(), music);
}

void pa::Sound::unregisterMusic(pa::Sound::Handle handle)
{
	m_musicList.erase(handle);
}