#ifndef APPLICATION_CONFIGURATOR_HPP
#define APPLICATION_CONFIGURATOR_HPP


class ApplicationConfigurator {
    private:
        int applicationConfig;
    public:
        ApplicationConfigurator() {
            applicationConfig = 2;
        }
        int applicationConfigFile() {
            return applicationConfig;
        }
};

#endif
