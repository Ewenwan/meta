#include "component_base.h"

namespace test
{
    class transform: public component_base
    {
    public:
        transform(entity_base* _in_owner):
        component_base(_in_owner, component_type::transform)
        {

        }
        static component_type static_type()
        {
            return component_type::transform;
        }
        Meta(stub_func) void on_created()
        {
            std::cout<<"on_create called from transform"<<std::endl;
        }
        Meta(stub_func(priority=11)) void on_enter_space()
        {
            std::cout<<"on_enter_space called from transform"<<std::endl;
        }
        Meta(stub_func(priority=5)) void on_leave_space()
        {
            std::cout<<"on_leave_space called from transform"<<std::endl;
        }
        Meta(stub_func(priority=10)) void on_destroy()
        {
            std::cout<<"on_destroy called from transform"<<std::endl;
        }
        Meta(rpc) void teleport_to(std::array<float, 3> dest);
        Meta(rpc) void jump();
        Meta(rpc) void walk_to(std::array<float, 3> dest);
        Meta(rpc) void follow_entity(const std::string& entity_id);
    };
}