#pragma once
#include <list>
#include "i_handler.hpp"

class Pipeline
{
    public:
        Pipeline() = default;
        virtual ~Pipeline() = default;
        void Handle(std::istream& stream) const;
        void PushHandler(std::shared_ptr<IHandler> handler);
        void Report(std::ostream& stream) const;
        const bool BuildSucceded() const;
        const std::string Error() const;
        static void BuildCounter(Pipeline&, char*, char*);
        static void BuildReplacer(Pipeline&, char*, char*, char*);

    private:
        std::list<std::shared_ptr<IHandler>> m_handlers;
};