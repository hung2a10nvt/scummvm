/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef SWORD25_SWORD25_H
#define SWORD25_SWORD25_H

#include "common/scummsys.h"
#include "engines/engine.h"

#include "sword25/console.h"
#include "sword25/detection.h"

namespace Common {
class Error;
}

namespace GUI {
class Debugger;
}

struct ADGameDescription;

/**
 * This is the namespace of the Sword25 engine.
 *
 * Status of this engine: ???
 *
 * Games using this engine:
 * - Broken Sword 2.5
 */
namespace Sword25 {

enum {
	kFileTypeHash = 0
};

enum {
	kDebugScript = 1,
	kDebugSound,
	kDebugInternalDebugger,
	kDebugResource,
};

#define MESSAGE_BASIC 1
#define MESSAGE_INTERMEDIATE 2
#define MESSAGE_DETAILED 3

class Sword25Engine : public Engine {
private:
	Common::Error appStart();
	bool appMain();
	bool appEnd();

	bool loadPackages();

protected:
	Common::Error run() override;
	bool hasFeature(EngineFeature f) const override;
// 	void pauseEngineIntern(bool pause);	// TODO: Implement this!!!
// 	void syncSoundSettings();	// TODO: Implement this!!!
// 	Common::Error loadGameState(int slot);	// TODO: Implement this?
// 	Common::Error saveGameState(int slot, const Common::String &desc, bool isAutosave = false);	// TODO: Implement this?
// 	bool canLoadGameStateCurrently();	// TODO: Implement this?
// 	bool canSaveGameStateCurrently();	// TODO: Implement this?

	void shutdown();

public:
	Sword25Engine(OSystem *syst, const ADGameDescription *gameDesc);
	~Sword25Engine() override;

	uint32 getGameFlags() const;

	const ADGameDescription *_gameDescription;
};

} // End of namespace Sword25

#endif
