#ifndef _GUISTRINGWHEEL_H
#define _GUISTRINGWHEEL_H

#include "gui/guilabel.h"
#include "sprite2d.h"

class GUISTRINGWHEEL : public GUIWIDGET
{
public:
	GUISTRINGWHEEL();

	~GUISTRINGWHEEL();

	virtual void SetAlpha(SCENENODE & scene, float value);

	virtual void SetVisible(SCENENODE & scene, bool value);

	virtual std::string GetDescription() const;

	virtual void SetDescription(const std::string & value);

	virtual bool ProcessInput(
		SCENENODE & scene,
		float cursorx, float cursory,
		bool cursordown, bool cursorjustup);

	virtual void Update(SCENENODE & scene, float dt);

	virtual std::string GetAction() const;

	void SetAction(const std::string & value);

	void SetupDrawable(
		SCENENODE & scene,
		std::tr1::shared_ptr<TEXTURE> bgtex,
		std::map<std::string, GUIOPTION> & optionmap,
		const std::string & setting,
		const FONT & font,
		float scalex, float scaley,
		float centerx, float centery,
		float w, float h, float z,
		std::ostream & error_output);

private:
	GUILABEL m_label_value;
	GUILABEL m_label_left;
	GUILABEL m_label_right;
	std::string m_description;
	std::string m_setting;
	std::string m_value;
	std::string m_action;
	std::string m_action_active;
	bool m_focus;

	Signal0 next_value, prev_value;
	Slot1<const std::string &> set_value;
	void SetValue(const std::string & value);

	GUISTRINGWHEEL(const GUISTRINGWHEEL & other);
};

#endif // _GUISTRINGWHEEL_H
