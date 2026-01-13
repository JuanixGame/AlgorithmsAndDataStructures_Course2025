#include "refugio.hpp"

Refugio::Refugio(const std::string& name, float defense, float attack)
    : EntidadGenerica(name)
    , m_defense(defense)
    , m_attack(attack)
{
}

void Refugio::showInfo() const
{
    std::cout << "🏠 Refugio: " << m_name << "\n";
    std::cout << "\t🛡️  Defensa: " << m_defense << "\n";
    std::cout << "\t⚔️  Ataque: " << m_attack << "\n";
    std::cout << "👥 Moradores: ";
    for (int refugee = 0; refugee < m_refugees.size(); refugee++)
    {
        std::cout << "\t - " << m_refugees.at(refugee) << std::endl;
    }
    std::cout << "\n";
    std::cout << "\t📦 Recursos: \n";
}

void Refugio::doAction() const
{
    std::runtime_error("Not implemented yet");
}

void Refugio::addRefugee(const std::string& refugee)
{
    m_refugees.push_back(refugee);
}

void Refugio::addResource(const std::string& resource, float amount)
{
    m_resources.push_back(std::pair<std::string, int>(resource,amount));
}

bool Refugio::consumeResource(const std::string& resource, float amount)
{// casos: el recurso no existe, la cantidad es negativa, no hay suficientes recursos
    if (amount<=0) return false;
    
    for (size_t i = 0; i < m_resources.size(); i++)
    {
        if (m_resources[i].first==resource)
        {
            if (m_resources[i].second>=amount)
            {
                m_resources[i].second-=amount;
                return true;
            }else {std::cout<<"La cantidad pedida, exede la contenida"<<std::endl; return false;}
        }
    }
    std::cout<<"El recurso pedido no existe"<<std::endl;
    return false;
}