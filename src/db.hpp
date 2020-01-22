#ifndef __MY_AWESOME_DATABASE_HPP___
#define __MY_AWESOME_DATABASE_HPP___

#include <memory>
#include <map>
#include <list>

#include <iostream>

template<class entity_t>
class database_c{
protected:
std::shared_ptr<std::map<int, entity_t>> _container;
public:
    database_c(std::shared_ptr<std::map<int, entity_t>> container_ = std::make_shared<std::map<int, entity_t>>()) {
        _container = container_;
    }
    std::map<int, entity_t> *get_container() const {
        return _container.get();
    }

    std::list<entity_t> get_all(){
        std::list<entity_t> ret;
        for (auto [k,v]:*_container) ret.push_back(v);
        return ret;
    }

    void create(entity_t e) {
        get_container().insert(get_container().size(), e);
    }

    std::entity_t getById(int id) {
        return get_container().find(id);
    }

    void deleteById(int id) {
        get_container().erase(id);
    }

    std::entity_t update(entity_t e, int idToUpdate) {
        entity_t eToUpdate = getById(idToUpdate);
        deleteById(idToUpdate);
        get_container().insert(idToUpdate, e);
        return e;
    }


};

#endif
