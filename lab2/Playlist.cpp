#include "Playlist.h"
#include <sstream>
#include <iomanip>

/*
Конструктор (Playlist)
Вход:           capacity — максимальное число треков в плейлисте (int).
Предусловия:    capacity должно быть больше 0.
Процесс:        Создаёт пустой плейлист заданной вместимости. Заносит вместимость в соответствующее свойство Capacity. Число треков (Count) устанавливается в 0.
Выход:          —
Постусловия:    Count == 0.
Исключения:     PlaylistException, если capacity <= 0.
*/
Playlist::Playlist(int capacity)
{
    if (capacity <= 0)
        throw PlaylistException("недопустимое значение вместимости = " + std::to_string(capacity));
    this->capacity = capacity;
    this->count = 0;
    this->tracks = new Track[capacity];
}

// Конструктор копирования
Playlist::Playlist(const Playlist &other)
{
    capacity = other.capacity;
    count = other.count;
    tracks = new Track[capacity];
    for (int i = 0; i < count; i++)
        tracks[i] = other.tracks[i];
}

// Конструктор
Playlist &Playlist::operator=(const Playlist &other)
{
    if (this == &other)
        return *this;
    delete[] tracks;
    capacity = other.capacity;
    count = other.count;
    tracks = new Track[capacity];
    for (int i = 0; i < count; i++)
        tracks[i] = other.tracks[i];
    return *this;
}

// Деструктор
Playlist::~Playlist()
{
    delete[] tracks;
}

// Индексатор
const Track &Playlist::operator[](int i) const
{
    if (i < 0 || i > count - 1)
        throw PlaylistException("неверное значение индекса i = " + std::to_string(i));
    return tracks[i];
}

// Индексатор
Track &Playlist::operator[](int i)
{
    if (i < 0 || i > count - 1)
        throw PlaylistException("неверное значение индекса i = " + std::to_string(i));
    return tracks[i];
}

/*
Равно (operator==)
Вход:           other — объект типа Playlist.
Предусловия:    Нет.
Процесс:        Возвращает true, если число треков совпадает и все треки на одинаковых позициях равны (в порядке следования).
Выход:          Значение типа bool.
Постусловия:    Нет.
*/
bool Playlist::operator==(const Playlist &other) const
{
    if (count != other.count)
        return false;
    for (int i = 0; i < count; i++)
    {
        if (tracks[i] != other.tracks[i])
            return false;
    }
    return true;
}

// Содержимость
bool Playlist::Contains(const Track &track) const
{
    for (int i = 0; i < count; i++)
    {
        if (tracks[i] == track)
            return true;
    }
    return false;
}

// Методы

/*
Добавить трек (Add)
Вход:           track типа Track.
Предусловия:    Count < Capacity (есть свободное место); в плейлисте не должно быть трека, равного добавляемому (см. равенство Track).
Процесс:        Добавляет трек в конец плейлиста, увеличивает Count на 1.
Выход:          —
Постусловия:    Count увеличился на 1.
Исключения:     PlaylistException при переполнении; PlaylistException при дубликате.
*/
void Playlist::Add(const Track &track)
{
    if (count >= capacity)
        throw PlaylistException("плейлист заполнен, вместимость = " + std::to_string(capacity));
    if (Contains(track))
        throw PlaylistException("трек уже есть в плейлисте: " + track.artist + " - " + track.title);
    tracks[count] = track;
    count++;
}

/*
Суммарная длительность (TotalDuration)
Вход:           Нет.
Предусловия:    Нет.
Процесс:        Суммирует durationSec всех треков плейлиста.
Выход:          Значение типа int (секунды).
Постусловия:    Нет.
*/
int Playlist::TotalDuration() const
{
    int total = 0;
    for (int i = 0; i < count; i++)
        total += tracks[i].durationSec;
    return total;
}

// Преобразовать в строку
std::string Playlist::ToString() const
{
    std::ostringstream out;
    for (int i = 0; i < count; i++)
    {
        int m = tracks[i].durationSec / 60;
        int s = tracks[i].durationSec % 60;
        out << tracks[i].artist << " - " << tracks[i].title
            << " (" << m << ":" << std::setw(2) << std::setfill('0') << s << ")\n";
    }
    return out.str();
}

// Merge, RemoveTracksOf и FindByArtist оставлены как самостоятельные:

/*
Объединить (Merge)
Вход:           other — объект типа Playlist.
Предусловия:    Суммарное число треков (с учётом исключения дубликатов) не должно превышать Capacity текущего плейлиста; при совпадении трека в обоих плейлистах он не дублируется, а пропускается.
Процесс:        Последовательно добавляет в текущий плейлист все треки из other, которых в нём ещё нет.
Выход:          —
Постусловия:    Count увеличивается на число реально добавленных (уникальных) треков.
Исключения:     PlaylistException, если вместимости не хватает для всех уникальных треков other.
*/
void Playlist::Merge(const Playlist &other)
{
    // Считаем новые треки
    int newTracksCount = 0;
    for (int i = 0; i < other.count; i++)
    {
        if (!Contains(other.tracks[i]))
        {
            newTracksCount++;
        }
    }
    // Украдено из Playlist::Add
    if (count + newTracksCount >= capacity)
    {
        throw PlaylistException("плейлист заполнен, вместимость: " + std::to_string(capacity));
    }

    // Добавляем треки в плейлист (ъЕЕЕЕЕЕЕ РОККККК)
    for (int i = 0; i < other.count; i++)
    {
        if (!Contains(other.tracks[i]))
        {
            tracks[count] = other.tracks[i];
            count++;
        }
    }
}

/*
Убрать треки исполнителя/треки другого плейлиста (RemoveTracksOf)
Вход:           other — объект типа Playlist.
Предусловия:    Хотя бы один трек из other должен присутствовать в текущем плейлисте.
Процесс:        Удаляет из текущего плейлиста все треки, которые встречаются в other; оставшиеся треки сдвигаются, сохраняя порядок.
Выход:          —
Постусловия:    Count уменьшается на число реально удалённых треков.
Исключения:     PlaylistException , если ни один трек из other не найден в текущем плейлисте.
*/
void Playlist::RemoveTracksOf(const Playlist &other)
{
    int removeTracksCount = 0;
    for (int i = 0; i < other.count; i++)
    {
        if (Contains(other.tracks[i]))
        {
            removeTracksCount++;
        }
    }

    if (!removeTracksCount)
    {
        throw PlaylistException("ни один трек на удаление не найден в плейлисте, найдено: " + std::to_string(removeTracksCount));
    }

    for (int i = 0; i < other.count; i++)
    {
        if (Contains(other.tracks[i]))
        {
            // Находим индекс для удаления трека
            int idx = -1;
            for (int j = 0; j < count; j++)
            {
                if (tracks[j] == other.tracks[i])
                {
                    idx = j;
                    break;
                }
            }

            // Сдвигаем оставшиеся треки
            if (idx != -1)
            {
                for (int j = idx; j < count - 1; j++)
                {
                    tracks[j] = tracks[j + 1];
                }
                count--;
            }
        }
    }
}

/*
Найти трек исполнителя (FindByArtist)
Вход:           artist типа std::string.
Предусловия:    Нет.
Процесс:        Ищет первый по порядку трек, у которого artist совпадает с переданным.
Выход:          Индекс найденного трека (int).
Постусловия:    Нет.
Исключения:     PlaylistException, если трек исполнителя не найден.
*/
int Playlist::FindByArtist(const std::string &artist) const
{
    if (artist.empty())
    {
        throw PlaylistException("поле с именем исполнителя не должно быть пустым!");
    }

    for (int i = 0; i < count; i++)
    {
        if (artist == tracks[i].artist)
            return i;
    }

    throw PlaylistException("трек исполнителя не найден, введённый исполнитель: " + artist);
}