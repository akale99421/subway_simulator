#include <exception>

 class EventNotFoundException : public std::exception {
    public:
        virtual const char* what() const noexcept  {
            return "Event not found";
        }
 };