#pragma once
#include <sstream>
#include "i_handler.hpp"

class AbstractHandler : public IHandler
{
    public:
        AbstractHandler();
        virtual ~AbstractHandler();
        virtual void Init() override;
        virtual void SetNextHandler(std::shared_ptr<IHandler> next) override;
        virtual void Handle(std::istream& stream) const override;
        virtual void Report(std::ostream& stream) const override;
        virtual const bool Ready() const override;
        virtual const std::string Error() const override;
        virtual void Finalize() override;

    protected:
        virtual std::string GetReport() const override;
        std::shared_ptr<IHandler> m_next_handler;
        std::ostringstream m_error_stream;
};