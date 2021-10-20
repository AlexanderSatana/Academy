#pragma once
#include <string>
#include <memory>

using namespace std;

class IHandler
{
    public:
        IHandler();
        virtual ~IHandler();
        virtual void Init() = 0;
        virtual void SetNextHandler(shared_ptr<IHandler> next) = 0;
        virtual void Handle(istream& stream) const = 0;
        virtual bool Ready() const = 0;
        virtual string Error() const = 0;
        virtual void Report(ostream& stream) const = 0;
        virtual void Finalize() = 0;

    protected:
        virtual string GetReport() const = 0;
};