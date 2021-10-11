#pragma once
#include <string>
#include <memory>

class IHandler
{
    public:
        IHandler();
        virtual ~IHandler();
        virtual void Init() = 0;
        virtual void SetNextHandler(std::shared_ptr<IHandler> next) = 0;
        virtual void Handle(std::istream& stream) const = 0;
        virtual const bool Ready() const = 0;
        virtual const std::string Error() const = 0;
        virtual void Report(std::ostream& stream) const = 0;
        virtual void Finalize() = 0;

    protected:
        virtual std::string GetReport() const = 0;
};