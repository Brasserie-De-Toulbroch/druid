#include <window.h>

DruidWindow::DruidWindow() {
  _central_widget.reset(new DruidCentralWidget());
  setCentralWidget(_central_widget.data());
}
