#include "Notifi.h"

Notifi* Notifi::notifi_ = nullptr;

Notifi::Notifi(QObject *parent)
	: QObject(parent)
{}

Notifi::~Notifi()
{}

Notifi * Notifi::getNotifi()
{
	if (notifi_ == nullptr) {
		notifi_ = new Notifi;
	}
	return notifi_;
}

//void Notifi::onSkinChange(const QColor &color) {
//
//}
