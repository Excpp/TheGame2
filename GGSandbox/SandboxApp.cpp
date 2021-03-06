#include <GGEngine/GGEngine.h>
#include <GGEngine/Utility/Time/Clock.h>

class SandboxApp : public Application
{
public:

	virtual void run() override;

	virtual ~SandboxApp() = default;

};



void SandboxApp::run()
{
	engine.startUp();

	while (engine.getModule<WindowModule>().getWin().isOpen())
	{
		updateClock();
		engine.update();
	}

	engine.shutdown();
}