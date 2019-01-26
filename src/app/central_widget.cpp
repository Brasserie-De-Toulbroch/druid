#include <central_widget.h>

DruidCentralWidget::DruidCentralWidget(const DruidDb* const db) : _db(db) {
  setupUi(this);

  _top_layout->insertWidget(0, &_menu);

  _right_layout->addWidget(&_timer);
  _right_layout->addWidget(&_volume);
  _right_layout->addWidget(&_notes);

  connect(&_menu, &DruidMenu::save, this, &DruidCentralWidget::save);
}

void DruidCentralWidget::save() {
  const QString title = _title->text();
  const QString sql = QString("insert into recipes values(%1)").arg(title);
  _db->exec(sql);
}
