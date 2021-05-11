//
//  Student.h
//  ds
//
//  Created by yangfeng on 2021/5/11.
//  Copyright © 2021 yangfeng. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include <string>

using namespace std;

struct Student {
    string name;
    int age;
    
    bool operator < (const Student &s) {
        return age < s.age;
    }
    
    friend ostream& operator<<(ostream &s, const Student &st) {
        s << "Student: " << st.name << ", " << st.age << endl;
        return s;
    }
};

#endif /* Student_h */
