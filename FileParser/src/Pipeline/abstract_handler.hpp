#pragma once
#include <sstream>
#include "i_handler.hpp"

class AbstractHandler : public IHandler
{
    public:
        AbstractHandler();
        virtual ~AbstractHandler();
        virtual void Init() override;
        virtual void SetNextHandler(shared_ptr<IHandler> next) override;
        virtual void Handle(istream& stream) const override;
        virtual void Report(ostream& stream) const override;
        virtual bool Ready() const override;
        virtual string Error() const override;
        virtual void Finalize() override;

    protected:
        virtual string GetReport() const override;
        shared_ptr<IHandler> m_next_handler;
        ostringstream m_error_stream;
};