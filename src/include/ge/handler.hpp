#ifndef GE_HANDLER_HPP
#define GE_HANDLER_HPP

#include <vector>
#include <iostream>

namespace ge {
    template <class HandlerType>
    class Handler {
    public:
        Handler(){}

        virtual ~Handler(){
            clean();
            clear();
        }

        template <class HType>
        void updateHandler(){
            clean();
            for(HType *hType : hTypes){ hType->update(); }
        }

        virtual void update(){ updateHandler<HandlerType>(); }
        virtual void render(){ for(HandlerType *hType : hTypes){ hType->render(); } }

        void add(HandlerType *hType, bool removing = false){
            if(removing){ remove(); }
            hTypes.push_back(hType);
        }

        void remove(){
            if(hTypes.empty()){ return; }
            deleteQueue.push_back(hTypes.at(hTypes.size() - 1));
            hTypes.erase(hTypes.begin() + hTypes.size() - 1);
        }

        void remove(int id){
            if(hTypes.empty()){ return; }
            for(unsigned int i = 0; i < hTypes.size(); i++){
                if(hTypes.at(i)->id == id){
                    deleteQueue.push_back(hTypes.at(i));
                    hTypes.erase(hTypes.begin() + i);
                }
            }
        }

        void clean(){
            if(!deleteQueue.empty()){
                for(HandlerType *hType : deleteQueue){ delete hType; }
                deleteQueue.clear();
            }
        }

        void clear(){
            for(HandlerType *hType : hTypes){ delete hType; }
            hTypes.clear();
        }

    protected:
        std::vector<HandlerType *> hTypes;
        std::vector<HandlerType *> deleteQueue;
    };
}

#endif // !GE_HANDLER_HPP

