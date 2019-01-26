#include <window.h>

DruidWindow::DruidWindow(const DruidDb* const db) {
  _central_widget.reset(new DruidCentralWidget(db));
  setCentralWidget(_central_widget.data());
}
