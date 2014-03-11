#include <iostream>
#include <vector>
#include "event.h"

using namespace std;

int main()
{
    vector<string> cities {"Екатеринбург", "Иваново", "Казань", "Киев", "Минск", "Москва", "Новосибирск", "Одесса", "Пенза", "Пермь", "Ростов-на-Дону", "Самара", "Санкт-Петербург", "Тюмень", "Харьков", "Челябинск", "Яхрома"};
    vector<string> names {"Бесплатный вебинар “Wi-Fi для чайников: основы технологии за 1 вебинар”", "Бесплатный вебинар “Олимпиада IT-Планета: как стать чемпионом Cisco?”", "ИТ-директор. Как эффективно управлять ИТ-отделом", "Проектирование сетей и сооружений связи. Современные технологические решения"};
    vector<int> types {EVENT_TYPE_CONFERENCE, EVENT_TYPE_WORKSHOP, EVENT_TYPE_DISCUSSION, EVENT_TYPE_LECTION, EVENT_TYPE_WEBINAR};

    vector<Event<>> events;
    for(int i = 0; i < 54; ++i) {
        time_t temp; time(&temp);
        events.push_back(Event<>(names[i % names.size()],
                         cities[i % cities.size()],
                         temp,
                         types[i % types.size()]));
    }

    for (Event<> e : events) {
        cout << e;
    }

    return 0;
}

