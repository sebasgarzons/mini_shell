#!/bin/bash

#Colours
greenColour="\e[0;32m\033[1m"
endColour="\033[0m\e[0m"
redColour="\e[0;31m\033[1m"
blueColour="\e[0;34m\033[1m"
yellowColour="\e[0;33m\033[1m"
purpleColour="\e[0;35m\033[1m"
turquoiseColour="\e[0;36m\033[1m"
grayColour="\e[0;37m\033[1m"
Cyan="\033[0;36m"

#ROOT PRIVILEGIES
if [[ $EUID -ne 0 ]]; then
        echo -e "$red You don't have Root privilegies, execute the script as root.$nc"
        exit 1
fi


sleep 1
#bash Analitica_blockchain.sh
trap ctrl_c INT 
function ctrl_c(){
    echo -e "\n${redColour}[!] saliendo ...\n ${sendColour}"
    tput cnorm; exit 1
}
#for i in $(seq  1 50); do echo -ne "${blueColor}H"; done;
echo -ne "\n\n\n"
sleep 0.05

echo -e "\t ${yellowColour}  (\`-').->  (\`-').->  (\`-')  _                   " && sleep 0.05
echo -e "\t   ( OO)_    (OO )__   ( OO).-/    <-.       <-.      " && sleep 0.05
echo -e "\t   (_)--\_)  ,--. ,'-' (,------.  ,--. )    ,--. )    ${endColour} "&& sleep 0.05
echo -e "\t ${redColour}  /    _ /  |  | |  |  |  .---'  |  (\`-')  |  (\`-')"&& sleep 0.05
echo -e "\t   \_..\`--.  |  \`-'  | (|  '--.   |  |OO )  |  |OO )"&& sleep 0.05
echo -e "\t   .-._)   \ |  .-.  |  |  .--'  (|  '__ | (|  '__ |  ${endColour} "&& sleep 0.05
echo -e "\t ${Cyan}  \       / |  | |  |  |  \`---.  |     |'  |     |' "&& sleep 0.05
echo -e "\t    \`-----'  \`--' \`--'  \`------'  \`-----'   \`-----'${endColour} "&& sleep 0.05

sleep 0.05
echo -ne "\n"
echo -e "\t\t\t${yellowColour}(${endColour}${grayColour}Hecho por ${endColour}${blueColour}Juan Duque - Sebastian Garzon - Laura Cadavid${endColour}${yellowColour})${endColour}"
echo -e "${Cyan}====>=====>=======>======>=====>====>====>=====>=======>======>=====>====>====>=====>=======>======>=====>====>====>=====>=======>======>=====>====> ${endColor}"
echo -ne "\n\n\n"

#for i in $(seq  1 50); do echo -ne "${blueColor}H"; done;
echo -e "\n"
function helpPanel()
{
    echo -e "\n\t${grayColor}Uso ./Analitica_blockchain.sh [✔] ${endColour}${yellowColor}\t${endcolor}"
    for i in $(seq 1 80);do echo -ne "${greenColour}-"; done; echo -ne
    echo -ne "\n\t${blueColour} [-e]\t Emular ${endColor}\t${redColour}\t.... Emular terminal${endColor}\n"
    echo -ne "\t${blueColour} [-h]\t help comand${endColor}\t${redColour}\t.... Tabla de ayuda${endColor}\n"
    echo -ne "\t${blueColour} [-R]\t view README.md ${endColor}\t${redColour}.... leer archivo${endColor}\n"
    echo -ne "\t${blueColour} [-i]\t Install Shell ${endColor}\t${redColour}\t.... instalaras el interprete${endColor}\n"



    tput cnorm; exit 1
}
function Unconfirmed_mode()
{
    sudo apt-get update

    tput cnorm; exit 1
}

#ESTA FUNCION INSTALA EL PROGRAMA Y AL MISMO TIEMPO NOS HACE UN UPDATE DE LOS REPOSITORIOS

function install_ ()
{
    #Sysupdate
    sudo apt-get update
    #Python
    sudo apt-get install python
    cp  Shell.sh /bin
    #Falta el de copiar y pegar en la bin

    if [ -d ]; then
        echo "Directory exists.[✔]"
    else
	    mkdir facebook
	    cd facebook
	    cd ..
    fi

    tput cnorm; exit 1
}

parameter_counter=0; while getopts "e:h:f:" arg; do
    case $arg in
        e) exploration_mode=$OPTARG; let parameter_counter +=1;;
        h) help_=$OPTARG; let parameter_counter += 1;;
        f) echo -e "\nPresionaste f";;
    esac
done

tput civis

if [ $parameter_counter -eq 0 ]; then 
    helpPanel
else
    if [ "echo $exploration_mode" == "echo $Unconfirmed_mode" ]; then
        Unconfirmed_mode
        banner
    fi
fi