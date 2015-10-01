#include "ChatMessageItem.h"

QColor ChatMessageItem::_textColor(Qt::black);
QColor ChatMessageItem::_timeColor(Qt::gray);

ChatItem::ItemType ChatMessageItem::type() const
{
	return CHAT_MESSAGE_ITEM;
}

QVariant ChatMessageItem::data(int column, int role) const
{
	switch(role)
	{
		case Qt::DisplayRole:
		case Qt::EditRole:
		{
			switch(column)
			{
				case 0:
					return _nickName;
				case 1:
					return _text;
				case 2:
					return _time;
				default:
					return QVariant();
			}
		}
		default:
		{
			return QVariant();
		}
	}
}

Qt::ItemFlags ChatMessageItem::flags(int column, Qt::ItemFlags flags) const
{
	if(column == 1)
	{
		return Qt::ItemIsEditable | flags;
	}
	else
	{
		return flags;
	}
}

void ChatMessageItem::paint(QPainter *painter, const QStyleOptionViewItem &option, int column) const
{
	Q_ASSERT(column >= 0 && column < 3);

	const QString *text = 0;
	int alignment = (int)(Qt::AlignRight | Qt::AlignTop);
	const QColor *color = 0;

	switch(column)
	{
		case 0:
			text = &_nickName;
			alignment = (int)(Qt::AlignLeft | Qt::AlignTop);
			color = &_nickColor;
			break;
		case 1:
			text = &_text;
			alignment = (int)(Qt::AlignLeft & Qt::AlignTop);
			color = &_textColor;
			break;
		case 2:
			text = &_time;
			color = &_timeColor;
			break;
		default:
			break;
	}

	if(text != 0)
	{
		if(color != 0)
		{
			painter->setPen(*color);
		}

		QRect rect = option.rect.adjusted(2, 2, 4, 4);

		painter->drawText(rect, alignment | Qt::TextWordWrap, *text);
	}
}

QSize ChatMessageItem::sizeHint(const QStyleOptionViewItem &option, int column) const
{
	Q_ASSERT(column >= 0 && column < 3);

	const QString *text = 0;

	switch(column)
	{
		case 0:
			text = &_nickName;
			break;
		case 1:
			text = &_text;
			break;
		case 2:
			text = &_time;
			break;
		default:
			break;
	}

	if(text != 0)
	{
		QRect rect = option.fontMetrics.boundingRect(option.rect, Qt::TextWordWrap, *text);

		rect.adjust(2, 2, 4, 4);
		return rect.size();
	}
	
	return QSize();
}

int ChatMessageItem::version() const
{
	// Change this value each time when you change read/write methods
	return 1;
}

void ChatMessageItem::read(QDataStream &ds, int version)
{
	switch(version)
	{
		// Don' put break after 2 or 3 case, only after case 1:
		/*
		case 2:
			readVersion2(ds);
		*/
		case 1:
			readVersion1(ds);
			break;
		default:
			Q_ASSERT(!"Version not supported");
			break;
	}
}

void ChatMessageItem::write(QDataStream &ds)
{
	writeVersion1(ds);
	// writeVersion2();
}

// Don't remake all methods, only serialize new members in new versions
void ChatMessageItem::readVersion1(QDataStream &ds)
{
	ds >> _nickName >> _text >> _time >> _nickColor;
}

void ChatMessageItem::writeVersion1(QDataStream &ds)
{
	ds << _nickName << _text << _time << _nickColor;
}
