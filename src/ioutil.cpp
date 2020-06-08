#include "ioutil.hpp"

bool IoUtil::writeAll(QIODevice &dst, QByteArray const & src)
{
    qint64 offset = 0;

    while(offset < src.size())
    {
        qint64 len = dst.write(src.data() + offset, src.size() - offset);
        if(len == 0)
            return false;
        offset += len;
    }

    return true;
}

QString IoUtil::size_human(qint64 size)
{
    if(size < 1024)
        return QString("%1 B").arg(size);

    float num = size;
    QStringList list;
    list << "KB" << "MB" << "GB" << "TB";

    QStringListIterator i(list);
    QString unit("B");

    while(num >= 1024.0 && i.hasNext())
    {
        unit = i.next();
        num /= 1024.0;
    }
    return QString().setNum(num,'f',2)+" "+unit;
}
