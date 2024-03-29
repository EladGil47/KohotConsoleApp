#ifndef KOHOT_MENU_HPP
#define KOHOT_MENU_HPP

#include <string>
#include <vector>

#ifdef _WIN32
#define CLEAR_SCREEN CLEAR_SCREEN
#else
#define CLEAR_SCREEN "clear"
#endif

class Menu {
protected:
  void displayMenu();
  virtual bool handle();

  bool m_stay_in_menu = true;
  bool m_exit_menus = false;

  std::vector<std::string> m_options;
  std::string m_header = "Menu : ";

  const std::string EXIT = "Exit";
  const std::string GO_BACK = "Go Back";

public:
  uint16_t getChoiceFromUser();
  void initializeOptions(std::vector<std::string> options);
  void initializeHeader(std::string header);
};
#endif // KOHOT_MENU_HPP