#pragma once
namespace UI
{
  void DisplayControls();
  struct UIElement
  {
    char icon[4];
    char info[10];
  };
  struct UIRow
  {
    int colIndex;
    std::array< UIElement, 2> elements;
  };

  extern UIRow init;
  extern UIRow init2;
  extern UIRow init3;

  void ArrangeRow(int, UIRow);
  void ArrangeUI(void* col);
}