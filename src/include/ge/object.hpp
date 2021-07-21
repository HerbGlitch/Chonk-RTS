#ifndef GE_OBJECT_HPP
#define GE_OBJECT_HPP

namespace ge {
    struct Data;

    class Object {
    public:
        Object(Data *data, unsigned int id = 0): data(data), id(id){}
        virtual ~Object(){};

        virtual void update() = 0;
        virtual void render() = 0;

        unsigned int getId(){ return id; }
    protected:
        Data *data;

        unsigned int id;
    };
}

#endif // !GE_OBJECT_HPP
