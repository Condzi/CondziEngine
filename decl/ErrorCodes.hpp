#pragma once

namespace ce
{
	namespace ErrorCode
	{
		enum class ResourceManager
		{
			NONE,
			//	-----
			// Loading errors
			//	-----

			// Cannot open cfg file with path to other cfg files with paths
			CFG_MASTER,
			// Cannot open cfg file with paths to textures
			CFG_PATHS_TEXTURES,
			// Cannot open cfg file with paths to fonts
			CFG_PATHS_FONTS,
			// Cannot open cfg file with paths to SoundBuffers 
			CFG_PATHS_SOUNDBUFFERS,

			// File is bad parsed
			CFG_MASTER_BAD_PARSED,
			CFG_PATHS_TEXTURES_BAD_PARSED,
			CFG_PATHS_FONTS_BAD_PARSED,
			CFG_PATHS_SOUNDBUFFERS_BAD_PARSED,

			// Cannot open texture file
			LOAD_CANNOTOPEN_TEXTURE,
			// Cannot open font file
			LOAD_CANNOTOPEN_FONT,
			// Cannot open SoundBuffer file
			LOAD_CANNOTOPEN_SOUNDBUFFER,

			//	-----
			// Getting errors
			//	-----

			CANNOT_GET_TEXTURE_CANNOT_FIND,
			CANNOT_GET_FONT_CANNOT_FIND,
			CANNOT_GET_SOUNDBUFFER_CANNOT_FIND
		};

		enum class StateManager
		{
			NONE,
			//	-----
			// Adding errors
			//	-----

			// There was state named the same
			ADD_SAME,

			//	-----
			// Run errors
			//	-----
			STATE_NOT_FOUND
		};
	}
}