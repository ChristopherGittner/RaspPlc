#include "parser/StlParser.h"

#include <vector>
#include <string>
#include <algorithm>

#include "common/Program.h"
#include "command/Command.h"
#include "command/LdCommand.h"
#include "command/LdpCommand.h"
#include "command/LdfCommand.h"
#include "command/LdiCommand.h"
#include "command/LdeCommand.h"
#include "command/LdgCommand.h"
#include "command/LdgeCommand.h"
#include "command/LdlCommand.h"
#include "command/LdleCommand.h"
#include "command/LdneCommand.h"
#include "command/AndCommand.h"
#include "command/AniCommand.h"
#include "command/AnbCommand.h"
#include "command/AndpCommand.h"
#include "command/AndfCommand.h"
#include "command/AndeCommand.h"
#include "command/AndgCommand.h"
#include "command/AndgeCommand.h"
#include "command/AndlCommand.h"
#include "command/AndleCommand.h"
#include "command/AndneCommand.h"
#include "command/OrCommand.h"
#include "command/OriCommand.h"
#include "command/OrbCommand.h"
#include "command/OrpCommand.h"
#include "command/OrfCommand.h"
#include "command/OreCommand.h"
#include "command/OrgCommand.h"
#include "command/OrgeCommand.h"
#include "command/OrlCommand.h"
#include "command/OrleCommand.h"
#include "command/OrneCommand.h"
#include "command/OutCommand.h"
#include "command/OuttimerCommand.h"
#include "command/PlfCommand.h"
#include "command/PlsCommand.h"
#include "command/SetCommand.h"
#include "command/RstCommand.h"
#include "command/InvCommand.h"
#include "command/FfCommand.h"
#include "command/EgpCommand.h"
#include "command/EgfCommand.h"
#include "command/MepCommand.h"
#include "command/MefCommand.h"
#include "command/MpsCommand.h"
#include "command/MrdCommand.h"
#include "command/MppCommand.h"
#include "command/AnddCommand.h"
#include "command/OrdCommand.h"
#include "command/XordCommand.h"
#include "command/MovCommand.h"
#include "command/MovpCommand.h"
#include "command/IncCommand.h"
#include "command/IncpCommand.h"
#include "command/DecCommand.h"
#include "command/DecpCommand.h"
#include "command/AddCommand.h"
#include "command/AddpCommand.h"
#include "command/DivCommand.h"
#include "command/DivpCommand.h"
#include "command/MulCommand.h"
#include "command/MulpCommand.h"
#include "command/SubCommand.h"
#include "command/SubpCommand.h"
#include "common/Exceptions.h"
#include "common/RaspPlc.h"
#include "device/Timer.h"

StlParser& StlParser::getInstance()
{
    static StlParser instance;
    return instance;
}

std::shared_ptr<Program> StlParser::parse(std::istream& is, const RaspPlc& plc)
{
    std::vector<std::shared_ptr<Command>> commands;

    std::string token;

    while(is >> token)
    {
        std::transform(token.begin(), token.end(), token.begin(), tolower);
        if(token == "ld")
        {
            std::string name;
            is >> name;

            std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

            commands.push_back(std::make_shared<LdCommand>(device));
        }
        else if(token == "ldi")
        {
            std::string name;
            is >> name;

            std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

            commands.push_back(std::make_shared<LdiCommand>(device));
        }
        else if(token == "ldp")
        {
            std::string name;
            is >> name;

            std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

            commands.push_back(std::make_shared<LdpCommand>(device));
        }
        else if(token == "ldf")
        {
            std::string name;
            is >> name;

            std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

            commands.push_back(std::make_shared<LdfCommand>(device));
        }
        else if(token == "ld=")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<LdeCommand>(deviceLeft, deviceRight));
        }
        else if(token == "ld>")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<LdgCommand>(deviceLeft, deviceRight));
        }
        else if(token == "ld>=")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<LdgeCommand>(deviceLeft, deviceRight));
        }
        else if(token == "ld<")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<LdlCommand>(deviceLeft, deviceRight));
        }
        else if(token == "ld<=")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<LdleCommand>(deviceLeft, deviceRight));
        }
        else if(token == "ld<>")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<LdneCommand>(deviceLeft, deviceRight));
        }
        else if(token == "and")
        {
            std::string name;
            is >> name;

            std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

            commands.push_back(std::make_shared<AndCommand>(device));
        }
        else if(token == "ani")
        {
            std::string name;
            is >> name;

            std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

            commands.push_back(std::make_shared<AniCommand>(device));
        }
        else if(token == "andp")
        {
            std::string name;
            is >> name;

            std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

            commands.push_back(std::make_shared<AndpCommand>(device));
        }
        else if(token == "andf")
        {
            std::string name;
            is >> name;

            std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

            commands.push_back(std::make_shared<AndfCommand>(device));
        }
        else if(token == "and=")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<AndeCommand>(deviceLeft, deviceRight));
        }
        else if(token == "and>")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<AndgCommand>(deviceLeft, deviceRight));
        }
        else if(token == "and>=")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<AndgeCommand>(deviceLeft, deviceRight));
        }
        else if(token == "and<")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<AndlCommand>(deviceLeft, deviceRight));
        }
        else if(token == "and<=")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<AndleCommand>(deviceLeft, deviceRight));
        }
        else if(token == "and<>")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<AndneCommand>(deviceLeft, deviceRight));
        }
        else if(token == "anb")
        {
            commands.push_back(std::make_shared<AnbCommand>());
        }
        else if(token == "or")
        {
            std::string name;
            is >> name;

            std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

            commands.push_back(std::make_shared<OrCommand>(device));
        }
        else if(token == "ori")
        {
            std::string name;
            is >> name;

            std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

            commands.push_back(std::make_shared<OriCommand>(device));
        }
        else if(token == "orp")
        {
            std::string name;
            is >> name;

            std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

            commands.push_back(std::make_shared<OrpCommand>(device));
        }
        else if(token == "orf")
        {
            std::string name;
            is >> name;

            std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

            commands.push_back(std::make_shared<OrfCommand>(device));
        }
        else if(token == "or=")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<OreCommand>(deviceLeft, deviceRight));
        }
        else if(token == "or>")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<OrgCommand>(deviceLeft, deviceRight));
        }
        else if(token == "or>=")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<OrgeCommand>(deviceLeft, deviceRight));
        }
        else if(token == "or<")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<OrlCommand>(deviceLeft, deviceRight));
        }
        else if(token == "or<=")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<OrleCommand>(deviceLeft, deviceRight));
        }
        else if(token == "or<>")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<OrneCommand>(deviceLeft, deviceRight));
        }
        else if(token == "orb")
        {
            commands.push_back(std::make_shared<OrbCommand>());
        }
        else if(token == "out")
        {
            std::string name;
            is >> name;

            if(name[0] == 't')
            {
                std::string durationDeviceName;
                is >> durationDeviceName;

                std::shared_ptr<Timer> timer = plc.findTimerByName(name);
                std::shared_ptr<DWordDevice> durationDevice = plc.findDWordDeviceByName(durationDeviceName);

                commands.push_back(std::make_shared<OuttimerCommand>(timer, durationDevice));
            }
            else
            {
                std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

                commands.push_back(std::make_shared<OutCommand>(device));
            }
        }
        else if(token == "plf")
        {
            std::string name;
            is >> name;

            std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

            commands.push_back(std::make_shared<PlfCommand>(device));
        }
        else if(token == "pls")
        {
            std::string name;
            is >> name;

            std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

            commands.push_back(std::make_shared<PlsCommand>(device));
        }
        else if(token == "set")
        {
            std::string name;
            is >> name;

            std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

            commands.push_back(std::make_shared<SetCommand>(device));
        }
        else if(token == "rst")
        {
            std::string name;
            is >> name;

            std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

            commands.push_back(std::make_shared<RstCommand>(device));
        }
        else if(token == "inv")
        {
            commands.push_back(std::make_shared<InvCommand>());
        }
        else if(token == "ff")
        {
            std::string name;
            is >> name;

            std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

            commands.push_back(std::make_shared<FfCommand>(device));
        }
        else if(token == "egf")
        {
            std::string name;
            is >> name;

            std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

            commands.push_back(std::make_shared<EgpCommand>(device));
        }
        else if(token == "egp")
        {
            std::string name;
            is >> name;

            std::shared_ptr<BitDevice> device = plc.findBitDeviceByName(name);

            commands.push_back(std::make_shared<EgfCommand>(device));
        }
        else if(token == "mep")
        {
            commands.push_back(std::make_shared<MepCommand>());
        }
        else if(token == "mef")
        {
            commands.push_back(std::make_shared<MefCommand>());
        }
        else if(token == "mps")
        {
            commands.push_back(std::make_shared<MpsCommand>());
        }
        else if(token == "mrd")
        {
            commands.push_back(std::make_shared<MrdCommand>());
        }
        else if(token == "mpp")
        {
            commands.push_back(std::make_shared<MppCommand>());
        }
        else if(token == "andd")
        {
            std::string deviceNameLeft, deviceNameRight, deviceNameDestination;
            is >> deviceNameLeft >> deviceNameRight >> deviceNameDestination;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);
            std::shared_ptr<DWordDevice> deviceDestination = plc.findDWordDeviceByName(deviceNameDestination);

            commands.push_back(std::make_shared<AnddCommand>(deviceLeft, deviceRight, deviceDestination));
        }
        else if(token == "ord")
        {
            std::string deviceNameLeft, deviceNameRight, deviceNameDestination;
            is >> deviceNameLeft >> deviceNameRight >> deviceNameDestination;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);
            std::shared_ptr<DWordDevice> deviceDestination = plc.findDWordDeviceByName(deviceNameDestination);

            commands.push_back(std::make_shared<OrdCommand>(deviceLeft, deviceRight, deviceDestination));
        }
        else if(token == "xord")
        {
            std::string deviceNameLeft, deviceNameRight, deviceNameDestination;
            is >> deviceNameLeft >> deviceNameRight >> deviceNameDestination;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);
            std::shared_ptr<DWordDevice> deviceDestination = plc.findDWordDeviceByName(deviceNameDestination);

            commands.push_back(std::make_shared<XordCommand>(deviceLeft, deviceRight, deviceDestination));
        }
        else if(token == "mov")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<MovCommand>(deviceLeft, deviceRight));
        }
        else if(token == "movp")
        {
            std::string deviceNameLeft, deviceNameRight;
            is >> deviceNameLeft >> deviceNameRight;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);

            commands.push_back(std::make_shared<MovpCommand>(deviceLeft, deviceRight));
        }
        else if(token == "inc")
        {
            std::string name;
            is >> name;

            std::shared_ptr<DWordDevice> device = plc.findDWordDeviceByName(name);

            commands.push_back(std::make_shared<IncCommand>(device));
        }
        else if(token == "incp")
        {
            std::string name;
            is >> name;

            std::shared_ptr<DWordDevice> device = plc.findDWordDeviceByName(name);

            commands.push_back(std::make_shared<IncpCommand>(device));
        }
        else if(token == "dec")
        {
            std::string name;
            is >> name;

            std::shared_ptr<DWordDevice> device = plc.findDWordDeviceByName(name);

            commands.push_back(std::make_shared<DecCommand>(device));
        }
        else if(token == "decp")
        {
            std::string name;
            is >> name;

            std::shared_ptr<DWordDevice> device = plc.findDWordDeviceByName(name);

            commands.push_back(std::make_shared<DecpCommand>(device));
        }
        else if(token == "add")
        {
            std::string deviceNameLeft, deviceNameRight, deviceNameDestination;
            is >> deviceNameLeft >> deviceNameRight >> deviceNameDestination;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);
            std::shared_ptr<DWordDevice> deviceDestination = plc.findDWordDeviceByName(deviceNameDestination);

            commands.push_back(std::make_shared<AddCommand>(deviceLeft, deviceRight, deviceDestination));
        }
        else if(token == "addp")
        {
            std::string deviceNameLeft, deviceNameRight, deviceNameDestination;
            is >> deviceNameLeft >> deviceNameRight >> deviceNameDestination;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);
            std::shared_ptr<DWordDevice> deviceDestination = plc.findDWordDeviceByName(deviceNameDestination);

            commands.push_back(std::make_shared<AddpCommand>(deviceLeft, deviceRight, deviceDestination));
        }
        else if(token == "div")
        {
            std::string deviceNameLeft, deviceNameRight, deviceNameDestination;
            is >> deviceNameLeft >> deviceNameRight >> deviceNameDestination;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);
            std::shared_ptr<DWordDevice> deviceDestination = plc.findDWordDeviceByName(deviceNameDestination);

            commands.push_back(std::make_shared<DivCommand>(deviceLeft, deviceRight, deviceDestination));
        }
        else if(token == "divp")
        {
            std::string deviceNameLeft, deviceNameRight, deviceNameDestination;
            is >> deviceNameLeft >> deviceNameRight >> deviceNameDestination;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);
            std::shared_ptr<DWordDevice> deviceDestination = plc.findDWordDeviceByName(deviceNameDestination);

            commands.push_back(std::make_shared<DivpCommand>(deviceLeft, deviceRight, deviceDestination));
        }
        else if(token == "mul")
        {
            std::string deviceNameLeft, deviceNameRight, deviceNameDestination;
            is >> deviceNameLeft >> deviceNameRight >> deviceNameDestination;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);
            std::shared_ptr<DWordDevice> deviceDestination = plc.findDWordDeviceByName(deviceNameDestination);

            commands.push_back(std::make_shared<MulCommand>(deviceLeft, deviceRight, deviceDestination));
        }
        else if(token == "mulp")
        {
            std::string deviceNameLeft, deviceNameRight, deviceNameDestination;
            is >> deviceNameLeft >> deviceNameRight >> deviceNameDestination;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);
            std::shared_ptr<DWordDevice> deviceDestination = plc.findDWordDeviceByName(deviceNameDestination);

            commands.push_back(std::make_shared<MulpCommand>(deviceLeft, deviceRight, deviceDestination));
        }
        else if(token == "sub")
        {
            std::string deviceNameLeft, deviceNameRight, deviceNameDestination;
            is >> deviceNameLeft >> deviceNameRight >> deviceNameDestination;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);
            std::shared_ptr<DWordDevice> deviceDestination = plc.findDWordDeviceByName(deviceNameDestination);

            commands.push_back(std::make_shared<SubCommand>(deviceLeft, deviceRight, deviceDestination));
        }
        else if(token == "subp")
        {
            std::string deviceNameLeft, deviceNameRight, deviceNameDestination;
            is >> deviceNameLeft >> deviceNameRight >> deviceNameDestination;

            std::shared_ptr<DWordDevice> deviceLeft = plc.findDWordDeviceByName(deviceNameLeft);
            std::shared_ptr<DWordDevice> deviceRight = plc.findDWordDeviceByName(deviceNameRight);
            std::shared_ptr<DWordDevice> deviceDestination = plc.findDWordDeviceByName(deviceNameDestination);

            commands.push_back(std::make_shared<SubpCommand>(deviceLeft, deviceRight, deviceDestination));
        }
        else
        {
            throw FailedToParseException(token);
        }
    }

    return std::make_shared<Program>(commands);
}
