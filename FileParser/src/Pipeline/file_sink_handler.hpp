#include <fstream>
#include "abstract_handler.hpp"

class FileSinkHandler : public AbstractHandler
{
    public:
        FileSinkHandler();
        FileSinkHandler(std::string);
        ~FileSinkHandler();
        void Init() override;
        void Handle(std::istream&) const override;
        const bool Ready() const override;
        void Finalize() override;

    private:
        std::string m_filename;
        std::string m_filename_duplicate;
        mutable std::ofstream m_ofstream;
};