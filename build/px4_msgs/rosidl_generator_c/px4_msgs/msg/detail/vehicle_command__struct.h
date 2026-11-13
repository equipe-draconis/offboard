// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from px4_msgs:msg/VehicleCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "px4_msgs/msg/vehicle_command.h"


#ifndef PX4_MSGS__MSG__DETAIL__VEHICLE_COMMAND__STRUCT_H_
#define PX4_MSGS__MSG__DETAIL__VEHICLE_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Constant 'MESSAGE_VERSION'.
enum
{
  px4_msgs__msg__VehicleCommand__MESSAGE_VERSION = 0ul
};

/// Constant 'VEHICLE_CMD_CUSTOM_0'.
/**
  * --- COMANDOS CUSTOMIZADOS E DE TESTE ---
  * Comando customizado de teste 0
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_CUSTOM_0 = 0
};

/// Constant 'VEHICLE_CMD_CUSTOM_1'.
/**
  * Comando customizado de teste 1
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_CUSTOM_1 = 1
};

/// Constant 'VEHICLE_CMD_CUSTOM_2'.
/**
  * Comando customizado de teste 2
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_CUSTOM_2 = 2
};

/// Constant 'VEHICLE_CMD_NAV_WAYPOINT'.
/**
  * --- COMANDOS DE NAVEGAÇÃO E MISSÃO (NAV_*) ---
  * param1: Tempo de espera [s] (ignorado por asa fixa, tempo pairando para multirotores)
  * param2: Raio de aceitação [m] (se atingido dentro da esfera, o waypoint é considerado alcançado)
  * param3: Raio de passagem [m] (0 para passar direto. >0 órbita horária, <0 órbita anti-horária)
  * param4: Ângulo de Yaw desejado no waypoint (multirotores)
  * param5 (double): Latitude do destino (WGS-84)
  * param6 (double): Longitude do destino (WGS-84)
  * param7: Altitude do destino (AMSL)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_NAV_WAYPOINT = 16
};

/// Constant 'VEHICLE_CMD_NAV_LOITER_UNLIM'.
/**
  * param3: Raio ao redor do ponto (>0 horário, <0 anti-horário)
  * param4: Ângulo de Yaw desejado
  * param5/6/7: Coordenadas globais de Loiter (Lat/Lon/Alt)
  * Mantém Loiter no ponto por tempo ilimitado
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_NAV_LOITER_UNLIM = 17
};

/// Constant 'VEHICLE_CMD_NAV_LOITER_TURNS'.
/**
  * Mantém Loiter no ponto por X voltas (param1 = Voltas)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_NAV_LOITER_TURNS = 18
};

/// Constant 'VEHICLE_CMD_NAV_LOITER_TIME'.
/**
  * Mantém Loiter no ponto por X segundos (param1 = Segundos)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_NAV_LOITER_TIME = 19
};

/// Constant 'VEHICLE_CMD_NAV_RETURN_TO_LAUNCH'.
/**
  * Executa a rotina de Retorno ao Ponto de Decolagem (RTL)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_NAV_RETURN_TO_LAUNCH = 20
};

/// Constant 'VEHICLE_CMD_NAV_LAND'.
/**
  * param4: Ângulo de Yaw desejado no pouso
  * param5/6/7: Coordenadas globais do pouso (Lat/Lon/Alt)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_NAV_LAND = 21
};

/// Constant 'VEHICLE_CMD_NAV_TAKEOFF'.
/**
  * param1: Pitch mínimo de decolagem (apenas asa fixa)
  * param4: Ângulo de Yaw em graus [0,360] no referencial NED
  * param5/6/7: Coordenadas globais de decolagem (Lat/Lon/Alt)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_NAV_TAKEOFF = 22
};

/// Constant 'VEHICLE_CMD_NAV_PRECLAND'.
/**
  * Inicia pouso de precisão baseado em sensores (IR, tags, visão)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_NAV_PRECLAND = 23
};

/// Constant 'VEHICLE_CMD_DO_ORBIT'.
/**
  * param1: Raio da órbita [m]
  * param2: Velocidade tangencial [m/s]
  * param3: Comportamento do Yaw durante a órbita (ver sub-enum ORBIT_YAW_BEHAVIOUR)
  * param5/6/7: Coordenadas do centro da órbita (X/Y/Z ou Lat/Lon/Alt)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_ORBIT = 34
};

/// Constant 'VEHICLE_CMD_DO_FIGUREEIGHT'.
/**
  * param1: Raio Maior [m]
  * param2: Raio Menor [m]
  * param3: Velocidade de avanço [m/s]
  * param4: Orientação angular do padrão
  * param5/6/7: Coordenadas do centro do padrão (Lat/Lon/Alt)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_FIGUREEIGHT = 35
};

/// Constant 'VEHICLE_CMD_NAV_ROI'.
/**
  * param1: Modo de Região de Interesse (ver sub-enum VEHICLE_ROI)
  * param2: Índice da missão ou ID do alvo rastreado
  * param3: Índice do ROI (permite gerenciar múltiplos alvos)
  * param5/6/7: Coordenadas de foco do ROI fixo (X/Y/Z)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_NAV_ROI = 80
};

/// Constant 'VEHICLE_CMD_NAV_PATHPLANNING'.
/**
  * param1: Obstacle Avoidance Local (0:Desativa, 1:Ativa, 2:Ativa e reseta mapa)
  * param2: Path Planning Global (0:Desativa, 1:Ativa, 2:Ativa e reseta grid, 3:Ativa e reseta rota)
  * param4: Ângulo de Yaw final desejado no objetivo [0,360]
  * param5/6/7: Coordenadas globais do objetivo final (Lat/Lon/Alt)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_NAV_PATHPLANNING = 81
};

/// Constant 'VEHICLE_CMD_NAV_VTOL_TAKEOFF'.
/**
  * Comandos específicos para aeronaves VTOL (Transição de asa fixa / multirotor)
  * Decolagem vertical seguida de transição para asa fixa
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_NAV_VTOL_TAKEOFF = 84
};

/// Constant 'VEHICLE_CMD_NAV_VTOL_LAND'.
/**
  * Transição para multirotor seguida de pouso vertical
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_NAV_VTOL_LAND = 85
};

/// Constant 'VEHICLE_CMD_NAV_GUIDED_LIMITS'.
/**
  * param1: Timeout de controle externo [s] (0 = sem timeout)
  * param2: Altitude mínima absoluta AMSL [m] (se violada, aborta e retoma missão)
  * param3: Altitude máxima absoluta AMSL [m] (se violada, aborta e retoma missão)
  * param4: Raio de movimento horizontal máximo [m] medido a partir da execução do comando
  * Define limites geográficos de segurança para controle externo (Offboard)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_NAV_GUIDED_LIMITS = 90
};

/// Constant 'VEHICLE_CMD_NAV_GUIDED_MASTER'.
/**
  * param1: System ID do controlador mestre
  * param2: Component ID do controlador mestre
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_NAV_GUIDED_MASTER = 91
};

/// Constant 'VEHICLE_CMD_NAV_DELAY'.
/**
  * param1: Delay de execução [s] (-1 para habilitar os campos de horário UTC nos params seguintes)
  * param2: Hora UTC [0-23] (-1 para ignorar)
  * param3: Minuto UTC [0-59] (-1 para ignorar)
  * param4: Segundo UTC [0-59]
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_NAV_DELAY = 93
};

/// Constant 'VEHICLE_CMD_NAV_LAST'.
/**
  * NOP - Marcador de limite superior para comandos do tipo NAV
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_NAV_LAST = 95
};

/// Constant 'VEHICLE_CMD_CONDITION_DELAY'.
/**
  * --- COMANDOS CONDICIONAIS DE MISSÃO (CONDITION_*) ---
  * Pausa a máquina de estados da missão por X segundos (param1)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_CONDITION_DELAY = 112
};

/// Constant 'VEHICLE_CMD_CONDITION_CHANGE_ALT'.
/**
  * Altera altitude na taxa de param1. Segura missão até atingir param7 (Alt final)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_CONDITION_CHANGE_ALT = 113
};

/// Constant 'VEHICLE_CMD_CONDITION_DISTANCE'.
/**
  * Segura missão até que a distância ao próximo WP seja menor que param1
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_CONDITION_DISTANCE = 114
};

/// Constant 'VEHICLE_CMD_CONDITION_YAW'.
/**
  * param1: Ângulo alvo [0,360] (0 = Norte)
  * param2: Velocidade angular do giro
  * param3: Direção (-1: Anti-horário, 1: Horário)
  * param4: Tipo de referência (0: Absoluto, 1: Relativo ao rumo atual)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_CONDITION_YAW = 115
};

/// Constant 'VEHICLE_CMD_CONDITION_LAST'.
/**
  * NOP - Marcador de limite superior para comandos condicionais
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_CONDITION_LAST = 159
};

/// Constant 'VEHICLE_CMD_CONDITION_GATE'.
/**
  * param1: Modo 2D (0: Ortogonal à rota planejada)
  * param2: Modo de altitude (0: Ignora altitude do gate)
  * param5/6/7: Posição do Gate (Lat/Lon/Alt)
  * Aguarda até cruzar um plano limite (Gate)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_CONDITION_GATE = 4501
};

/// Constant 'VEHICLE_CMD_DO_SET_MODE'.
/**
  * --- COMANDOS DE AÇÃO IMEDIATA (DO_*) ---
  * Altera o modo do sistema de acordo com o enum MAV_MODE (param1)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_SET_MODE = 176
};

/// Constant 'VEHICLE_CMD_DO_JUMP'.
/**
  * param1: Número de sequência (ID) do item da missão alvo
  * param2: Contagem de repetições do ciclo
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_JUMP = 177
};

/// Constant 'VEHICLE_CMD_DO_CHANGE_SPEED'.
/**
  * param1: Tipo de velocidade (0: Airspeed, 1: Groundspeed, 2: Climb, 3: Descend)
  * param2: Velocidade alvo [m/s] (-1 para manter inalterado)
  * param3: Aceleração/Throttle em porcentagem [%] (-1 para manter inalterado)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_CHANGE_SPEED = 178
};

/// Constant 'VEHICLE_CMD_DO_SET_HOME'.
/**
  * param1: Escolha da referência (1: Usa posição atual do GPS, 0: Usa coordenadas dos params 5/6/7)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_SET_HOME = 179
};

/// Constant 'VEHICLE_CMD_DO_SET_PARAMETER'.
/**
  * param1: ID numérico mapeado do parâmetro interno do firmware
  * param2: Valor a ser injetado no parâmetro
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_SET_PARAMETER = 180
};

/// Constant 'VEHICLE_CMD_DO_SET_RELAY'.
/**
  * param1: Número identificador do relé físico (GPIO Out)
  * param2: Estado (1: Ligado, 0: Desligado)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_SET_RELAY = 181
};

/// Constant 'VEHICLE_CMD_DO_REPEAT_RELAY'.
/**
  * param1: ID do relé | param2: Ciclos de repetição | param3: Período do ciclo
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_REPEAT_RELAY = 182
};

/// Constant 'VEHICLE_CMD_DO_REPEAT_SERVO'.
/**
  * param1: Canal do Servo | param2: Pulso PWM [us] (Ex: 1000 a 2000) | param3: Ciclos | param4: Tempo [s]
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_REPEAT_SERVO = 184
};

/// Constant 'VEHICLE_CMD_DO_FLIGHTTERMINATION'.
/**
  * Ativa terminação forçada de voo imediatamente (Corte de motores/Paraquedas) se param1 > 0.5
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_FLIGHTTERMINATION = 185
};

/// Constant 'VEHICLE_CMD_DO_CHANGE_ALTITUDE'.
/**
  * param1: Altitude alvo | param2: Frame de referência da altitude
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_CHANGE_ALTITUDE = 186
};

/// Constant 'VEHICLE_CMD_DO_SET_ACTUATOR'.
/**
  * param1 a param6: Valores de controle direto para as saídas de atuadores 1 a 6 | param7: Índice do grupo
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_SET_ACTUATOR = 187
};

/// Constant 'VEHICLE_CMD_DO_LAND_START'.
/**
  * param5/6: Coordenadas aproximadas para busca do circuito de pouso mais próximo na missão
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_LAND_START = 189
};

/// Constant 'VEHICLE_CMD_DO_GO_AROUND'.
/**
  * Comando de arremetida (Go-Around) para abortar pouso autônomo com segurança. param1 = Altitude de escape
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_GO_AROUND = 191
};

/// Constant 'VEHICLE_CMD_DO_REPOSITION'.
/**
  * param1: Velocidade de aproximação | param2: Bitmask de eixos | param3: Raio loiter (asa fixa) | param4: Yaw desejado
  * param5/6/7: Coordenadas espaciais do novo alvo de posicionamento (Lat/Lon/Alt)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_REPOSITION = 192
};

/// Constant 'VEHICLE_CMD_DO_PAUSE_CONTINUE'.
/**
  * Alterna estados de pausa e retomada de missões ou trajetórias automáticas
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_PAUSE_CONTINUE = 193
};

/// Constant 'VEHICLE_CMD_DO_SET_ROI_LOCATION'.
/**
  * Comandos de apontamento estático do sensor/câmera (ROI)
  * Aponta câmera para localização fixa (param5/6/7)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_SET_ROI_LOCATION = 195
};

/// Constant 'VEHICLE_CMD_DO_SET_ROI_WPNEXT_OFFSET'.
/**
  * Aponta câmera para o próximo WP aplicando offsets em param5(Pitch), param6(Roll) e param7(Yaw)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_SET_ROI_WPNEXT_OFFSET = 196
};

/// Constant 'VEHICLE_CMD_DO_SET_ROI_NONE'.
/**
  * Cancela rastreamento de ROI atual e retorna sensores para a orientação padrão
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_SET_ROI_NONE = 197
};

/// Constant 'VEHICLE_CMD_DO_CONTROL_VIDEO'.
/**
  * param1: ID da Câmera (-1 = todas) | param2: Transmissão (0: off, 1: compresso, 2: raw) | param3: Modo (0: streaming, >0: captura a cada N s) | param4: Gravação
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_CONTROL_VIDEO = 200
};

/// Constant 'VEHICLE_CMD_DO_SET_ROI'.
/**
  * Controle genérico de ROI (idêntico ao VEHICLE_CMD_NAV_ROI, mas de execução imediata)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_SET_ROI = 201
};

/// Constant 'VEHICLE_CMD_DO_DIGICAM_CONTROL'.
/**
  * Gatilho direto de controle legado para câmeras digitais
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_DIGICAM_CONTROL = 203
};

/// Constant 'VEHICLE_CMD_DO_MOUNT_CONFIGURE'.
/**
  * param1: Modo de operação do Mount (ver sub-enum MAV_MOUNT_MODE)
  * param2: Ativa estabilização de Roll (1: sim, 0: não) | param3: Estabilização de Pitch | param4: Estabilização de Yaw
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_MOUNT_CONFIGURE = 204
};

/// Constant 'VEHICLE_CMD_DO_MOUNT_CONTROL'.
/**
  * param1: Pitch/Lat | param2: Roll/Lon | param3: Yaw/Alt (depende do modo de operação definido no param7)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_MOUNT_CONTROL = 205
};

/// Constant 'VEHICLE_CMD_DO_SET_CAM_TRIGG_DIST'.
/**
  * Configura disparo de câmera por distância métrica espacial percorrida (param1 = Distância)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_SET_CAM_TRIGG_DIST = 206
};

/// Constant 'VEHICLE_CMD_DO_FENCE_ENABLE'.
/**
  * Ativa ou desativa cercas geográficas virtuais / Geofence (param1: 1=Ativa, 0=Desativa)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_FENCE_ENABLE = 207
};

/// Constant 'VEHICLE_CMD_DO_PARACHUTE'.
/**
  * Controle manual de ejeção do paraquedas (param1: ver sub-enum PARACHUTE_ACTION)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_PARACHUTE = 208
};

/// Constant 'VEHICLE_CMD_DO_MOTOR_TEST'.
/**
  * param1: ID/Instância do motor | param2: Tipo de comando de aceleração | param3: Valor do throttle | param4: Timeout
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_MOTOR_TEST = 209
};

/// Constant 'VEHICLE_CMD_DO_INVERTED_FLIGHT'.
/**
  * Força voo invertido em aeronaves homologadas (param1: 1=Invertido, 0=Normal)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_INVERTED_FLIGHT = 210
};

/// Constant 'VEHICLE_CMD_DO_GRIPPER'.
/**
  * Acionamento de garras de carga/servos de liberação (ver sub-enum GRIPPER_ACTION)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_GRIPPER = 211
};

/// Constant 'VEHICLE_CMD_DO_SET_CAM_TRIGG_INTERVAL'.
/**
  * Configura disparo de câmera baseado em intervalos fixos de tempo (param1 = Intervalo)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_SET_CAM_TRIGG_INTERVAL = 214
};

/// Constant 'VEHICLE_CMD_DO_MOUNT_CONTROL_QUAT'.
/**
  * Controle de gimbals tridimensionais usando quatérnios de atitude espacial diretos (param1=qw, param2=qx, param3=qy, param4=qz)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_MOUNT_CONTROL_QUAT = 220
};

/// Constant 'VEHICLE_CMD_DO_GUIDED_MASTER'.
/**
  * Duplicata operacional imediata do comando NAV_GUIDED_MASTER
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_GUIDED_MASTER = 221
};

/// Constant 'VEHICLE_CMD_DO_GUIDED_LIMITS'.
/**
  * Duplicata operacional imediata do comando NAV_GUIDED_LIMITS
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_GUIDED_LIMITS = 222
};

/// Constant 'VEHICLE_CMD_DO_LAST'.
/**
  * NOP - Marcador de limite superior para blocos operacionais de ação imediata
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_LAST = 240
};

/// Constant 'VEHICLE_CMD_PREFLIGHT_CALIBRATION'.
/**
  * --- PROCESSOS DE PRÉ-VOO E MANUTENÇÃO (PREFLIGHT_*) ---
  * Executa calibração geral de sensores (Aceito apenas em solo/disarmed)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_PREFLIGHT_CALIBRATION = 241
};

/// Constant 'PREFLIGHT_CALIBRATION_TEMPERATURE_CALIBRATION'.
/**
  * Sub-parâmetro injetado em param1 para iniciar calibração térmica de sensores
 */
enum
{
  px4_msgs__msg__VehicleCommand__PREFLIGHT_CALIBRATION_TEMPERATURE_CALIBRATION = 3
};

/// Constant 'VEHICLE_CMD_PREFLIGHT_SET_SENSOR_OFFSETS'.
/**
  * param1: Sensor alvo (0:giros, 1:acelerômetros, 2:magnetômetro, 3:barômetro, 4:optical flow)
  * param2/3/4: Offsets brutos para os eixos X, Y e Z nas unidades nativas do sensor alvo
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_PREFLIGHT_SET_SENSOR_OFFSETS = 242
};

/// Constant 'VEHICLE_CMD_PREFLIGHT_UAVCAN'.
/**
  * Dispara mapeamento dinâmico de nós atuadores via barramento CAN/UAVCAN (param1=1 inicia)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_PREFLIGHT_UAVCAN = 243
};

/// Constant 'VEHICLE_CMD_PREFLIGHT_STORAGE'.
/**
  * param1: Controle de parâmetros (0: Lê da Flash/EEPROM, 1: Grava parâmetros atuais na Flash)
  * param2: Controle de missões (0: Lê da Flash/EEPROM, 1: Grava missão atual na Flash)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_PREFLIGHT_STORAGE = 245
};

/// Constant 'VEHICLE_CMD_PREFLIGHT_REBOOT_SHUTDOWN'.
/**
  * param1: Piloto Automático (0: NOP, 1: Reboot PX4, 2: Shutdown PX4)
  * param2: Companion Computer / OBC (0: NOP, 1: Reboot Raspberry/Odroid, 2: Shutdown OBC)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_PREFLIGHT_REBOOT_SHUTDOWN = 246
};

/// Constant 'VEHICLE_CMD_OBLIQUE_SURVEY'.
/**
  * Controle de levantamentos aerofotogramétricos oblíquos (Mapeamento 3D complexo de fachadas)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_OBLIQUE_SURVEY = 260
};

/// Constant 'VEHICLE_CMD_DO_SET_STANDARD_MODE'.
/**
  * Força o acionamento de modos padrão MAVLink estruturados
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_SET_STANDARD_MODE = 262
};

/// Constant 'VEHICLE_CMD_GIMBAL_DEVICE_INFORMATION'.
/**
  * Requisita metadados estruturados de recursos e versão de hardware do gimbal conectado
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_GIMBAL_DEVICE_INFORMATION = 283
};

/// Constant 'VEHICLE_CMD_MISSION_START'.
/**
  * --- FLUXO PRINCIPAL E GERENCIAMENTO DE HARDWARE ---
  * param1: ID do item inicial da missão onde o sequenciador deve começar
  * param2: ID do item final onde a missão será dada por encerrada automaticamente
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_MISSION_START = 300
};

/// Constant 'VEHICLE_CMD_ACTUATOR_TEST'.
/**
  * Executa movimentação de teste de atuadores individuais (param1=Valor [-1,1], param2=Timeout)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_ACTUATOR_TEST = 310
};

/// Constant 'VEHICLE_CMD_CONFIGURE_ACTUATOR'.
/**
  * Envia diretivas em tempo real de reconfiguração de funções das saídas físicas
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_CONFIGURE_ACTUATOR = 311
};

/// Constant 'VEHICLE_CMD_COMPONENT_ARM_DISARM'.
/**
  * param1: Estado de armamento desejado (1: Armar motores, 0: Desarmar sistema de propulsão)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_COMPONENT_ARM_DISARM = 400
};

/// Constant 'VEHICLE_CMD_RUN_PREARM_CHECKS'.
/**
  * Força a re-execução imediata dos testes internos de segurança pré-armamento (Pre-flight safety checks)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_RUN_PREARM_CHECKS = 401
};

/// Constant 'VEHICLE_CMD_INJECT_FAILURE'.
/**
  * Injeta falhas de hardware via software para testes de redundância (SITL/HITL)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_INJECT_FAILURE = 420
};

/// Constant 'VEHICLE_CMD_START_RX_PAIR'.
/**
  * Inicializa pareamento de receptores de rádio RC (param1: 0=Spektrum | param2: 0=DSM2, 1=DSMX)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_START_RX_PAIR = 500
};

/// Constant 'VEHICLE_CMD_REQUEST_MESSAGE'.
/**
  * Solicita envio pontual de uma instância de mensagem uORB/MAVLink específica
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_REQUEST_MESSAGE = 512
};

/// Constant 'VEHICLE_CMD_REQUEST_CAMERA_INFORMATION'.
/**
  * Requisita dados estruturados estáticos de capacidades da câmera (CAMERA_INFORMATION)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_REQUEST_CAMERA_INFORMATION = 521
};

/// Constant 'VEHICLE_CMD_SET_CAMERA_MODE'.
/**
  * Alterna modos internos de captura da câmera (Ex: Modo foto vs Modo gravação de vídeo)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_SET_CAMERA_MODE = 530
};

/// Constant 'VEHICLE_CMD_SET_CAMERA_ZOOM'.
/**
  * Controla nível de zoom ótico/digital da câmera embarcada
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_SET_CAMERA_ZOOM = 531
};

/// Constant 'VEHICLE_CMD_SET_CAMERA_FOCUS'.
/**
  * Ajusta foco (manual/automático) das lentes do payload óptico
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_SET_CAMERA_FOCUS = 532
};

/// Constant 'VEHICLE_CMD_DO_GIMBAL_MANAGER_PITCHYAW'.
/**
  * Controle avançado e arbitragem de gimbals de câmera via arquitetura Gimbal Manager do MAVLink v2
  * Envia setpoints diretos de malha fechada de Pitch e Yaw ao gerenciador do Gimbal
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_GIMBAL_MANAGER_PITCHYAW = 1000
};

/// Constant 'VEHICLE_CMD_DO_GIMBAL_MANAGER_CONFIGURE'.
/**
  * Define hierarquia e prioridades de controle (SysID/CompID primário vs secundário)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_GIMBAL_MANAGER_CONFIGURE = 1001
};

/// Constant 'VEHICLE_CMD_IMAGE_START_CAPTURE'.
/**
  * Inicia disparo sequencial de captura de fotos
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_IMAGE_START_CAPTURE = 2000
};

/// Constant 'VEHICLE_CMD_DO_TRIGGER_CONTROL'.
/**
  * Habilita ou desabilita o subsistema físico automatizado de trigger de câmera do PX4
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_TRIGGER_CONTROL = 2003
};

/// Constant 'VEHICLE_CMD_VIDEO_START_CAPTURE'.
/**
  * Inicia gravação contínua de fluxo de vídeo digital
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_VIDEO_START_CAPTURE = 2500
};

/// Constant 'VEHICLE_CMD_VIDEO_STOP_CAPTURE'.
/**
  * Interrompe gravação de fluxo de vídeo e fecha o arquivo gerado
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_VIDEO_STOP_CAPTURE = 2501
};

/// Constant 'VEHICLE_CMD_LOGGING_START'.
/**
  * Inicia a transmissão em tempo real de logs estruturados em formato ULog via link de telemetria
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_LOGGING_START = 2510
};

/// Constant 'VEHICLE_CMD_LOGGING_STOP'.
/**
  * Interrompe a transmissão de streaming de ULog ativo
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_LOGGING_STOP = 2511
};

/// Constant 'VEHICLE_CMD_CONTROL_HIGH_LATENCY'.
/**
  * Gerencia o tráfego e ativação de links de dados de alta latência (Ex: Telemetria via Satélite/Iridium)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_CONTROL_HIGH_LATENCY = 2600
};

/// Constant 'VEHICLE_CMD_DO_VTOL_TRANSITION'.
/**
  * Força a transição manual imediata de estado de voo em VTOL (Multirotor <-> Asa Fixa)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_VTOL_TRANSITION = 3000
};

/// Constant 'VEHICLE_CMD_ARM_AUTHORIZATION_REQUEST'.
/**
  * Requisição de validação externa em sistemas com chaves de armamento centralizadas de segurança
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_ARM_AUTHORIZATION_REQUEST = 3001
};

/// Constant 'VEHICLE_CMD_PAYLOAD_PREPARE_DEPLOY'.
/**
  * Prepara a máquina de estados do payload para ejeção/operação dentro do plano de voo
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_PAYLOAD_PREPARE_DEPLOY = 30001
};

/// Constant 'VEHICLE_CMD_PAYLOAD_CONTROL_DEPLOY'.
/**
  * Executa e controla dinamicamente o disparo ou deploy do mecanismo do payload
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_PAYLOAD_CONTROL_DEPLOY = 30002
};

/// Constant 'VEHICLE_CMD_FIXED_MAG_CAL_YAW'.
/**
  * param5/6: Posição do sensor (se zero, assume posição GPS atual) | param7: Proa/Yaw de referência conhecida
  * Calibração ultra-rápida de magnetômetro baseada em tabelas magnéticas globais (WMM) e proa conhecida
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_FIXED_MAG_CAL_YAW = 42006
};

/// Constant 'VEHICLE_CMD_DO_WINCH'.
/**
  * Comanda a operação mecânica de guinchos/cabos de resgate e entrega de carga
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_DO_WINCH = 42600
};

/// Constant 'VEHICLE_CMD_EXTERNAL_POSITION_ESTIMATE'.
/**
  * Comandos de correção externa para algoritmos de estimação de estado (EKF2) em cenários de navegação estimada (Dead Reckoning)
  * Reseta/Injeta posição global externa estimada no filtro de Kalman
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_EXTERNAL_POSITION_ESTIMATE = 43003
};

/// Constant 'VEHICLE_CMD_EXTERNAL_WIND_ESTIMATE'.
/**
  * Injeta vetor de estimativa de vento externo para ajuste de controle aerodinâmico
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_EXTERNAL_WIND_ESTIMATE = 43004
};

/// Constant 'VEHICLE_CMD_PX4_INTERNAL_START'.
/**
  * --- EXTENSÕES INTERNAS EXCLUSIVAS DO ECOSSISTEMA PX4 ---
  * Marcador inicial para comandos exclusivos que operam acima do limite de 16-bits do MAVLink
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_PX4_INTERNAL_START = 65537ul
};

/// Constant 'VEHICLE_CMD_SET_GPS_GLOBAL_ORIGIN'.
/**
  * param5/6/7: Coordenadas de origem física local (Lat/Lon/Alt AMSL vinda do receptor GNSS)
  * Define a origem geográfica global absoluta que representará o ponto (0,0,0) local do EKF2
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_SET_GPS_GLOBAL_ORIGIN = 100000ul
};

/// Constant 'VEHICLE_CMD_SET_NAV_STATE'.
/**
  * param1: Estado de navegação alvo mapeado diretamente conforme a máquina de estados interna do Commander do PX4
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_CMD_SET_NAV_STATE = 100001ul
};

/// Constant 'VEHICLE_MOUNT_MODE_RETRACT'.
/**
  * --- SUB-ENUMERATIONS E MÁSCARAS DE DADOS PARA PARÂMETROS ESPECÍFICOS ---
  * Modos de operação de Gimbal/Mount (Injetados via param1 ou param7 em comandos de Mount)
  * Recolhe o gimbal para a posição de proteção, desativa estabilização e desliga motores
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_MOUNT_MODE_RETRACT = 0
};

/// Constant 'VEHICLE_MOUNT_MODE_NEUTRAL'.
/**
  * Move o gimbal para o centro neutro estático alinhado com a estrutura física da aeronave
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_MOUNT_MODE_NEUTRAL = 1
};

/// Constant 'VEHICLE_MOUNT_MODE_MAVLINK_TARGETING'.
/**
  * Transfere o controle dos eixos para setpoints dinâmicos via MAVLink com estabilização ativa
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_MOUNT_MODE_MAVLINK_TARGETING = 2
};

/// Constant 'VEHICLE_MOUNT_MODE_RC_TARGETING'.
/**
  * Vincula o controle de apontamento diretamente aos canais mapeados no rádio controle (RC)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_MOUNT_MODE_RC_TARGETING = 3
};

/// Constant 'VEHICLE_MOUNT_MODE_GPS_POINT'.
/**
  * Trava o foco da câmera apontado fixamente para uma coordenada global (Lat/Lon/Alt)
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_MOUNT_MODE_GPS_POINT = 4
};

/// Constant 'VEHICLE_MOUNT_MODE_ENUM_END'.
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_MOUNT_MODE_ENUM_END = 5
};

/// Constant 'VEHICLE_ROI_NONE'.
/**
  * Modos de operação de Região de Interesse / ROI (Injetados via param1)
  * Cancela foco em alvos, sensores retornam para comportamento padrão de voo
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_ROI_NONE = 0
};

/// Constant 'VEHICLE_ROI_WPNEXT'.
/**
  * Mantém os sensores apontados continuamente na direção do próximo waypoint da rota
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_ROI_WPNEXT = 1
};

/// Constant 'VEHICLE_ROI_WPINDEX'.
/**
  * Trava o apontamento dos sensores para um waypoint específico da lista pelo seu ID
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_ROI_WPINDEX = 2
};

/// Constant 'VEHICLE_ROI_LOCATION'.
/**
  * Fixa o apontamento dos sensores para uma coordenada geográfica estática no espaço
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_ROI_LOCATION = 3
};

/// Constant 'VEHICLE_ROI_TARGET'.
/**
  * Habilita rastreamento contínuo de um alvo dinâmico móvel rastreado pelo sistema
 */
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_ROI_TARGET = 4
};

/// Constant 'VEHICLE_ROI_ENUM_END'.
enum
{
  px4_msgs__msg__VehicleCommand__VEHICLE_ROI_ENUM_END = 5
};

/// Constant 'PARACHUTE_ACTION_DISABLE'.
/**
  * Ações de atuação do subsistema de paraquedas de emergência
 */
enum
{
  px4_msgs__msg__VehicleCommand__PARACHUTE_ACTION_DISABLE = 0
};

/// Constant 'PARACHUTE_ACTION_ENABLE'.
enum
{
  px4_msgs__msg__VehicleCommand__PARACHUTE_ACTION_ENABLE = 1
};

/// Constant 'PARACHUTE_ACTION_RELEASE'.
/**
  * Ejeta fisicamente o paraquedas cortando os motores no processo
 */
enum
{
  px4_msgs__msg__VehicleCommand__PARACHUTE_ACTION_RELEASE = 2
};

/// Constant 'FAILURE_UNIT_SENSOR_GYRO'.
/**
  * Mapeamento de unidades de hardware para o comando de injeção de falhas simuladas (VEHICLE_CMD_INJECT_FAILURE)
 */
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_UNIT_SENSOR_GYRO = 0
};

/// Constant 'FAILURE_UNIT_SENSOR_ACCEL'.
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_UNIT_SENSOR_ACCEL = 1
};

/// Constant 'FAILURE_UNIT_SENSOR_MAG'.
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_UNIT_SENSOR_MAG = 2
};

/// Constant 'FAILURE_UNIT_SENSOR_BARO'.
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_UNIT_SENSOR_BARO = 3
};

/// Constant 'FAILURE_UNIT_SENSOR_GPS'.
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_UNIT_SENSOR_GPS = 4
};

/// Constant 'FAILURE_UNIT_SENSOR_OPTICAL_FLOW'.
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_UNIT_SENSOR_OPTICAL_FLOW = 5
};

/// Constant 'FAILURE_UNIT_SENSOR_VIO'.
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_UNIT_SENSOR_VIO = 6
};

/// Constant 'FAILURE_UNIT_SENSOR_DISTANCE_SENSOR'.
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_UNIT_SENSOR_DISTANCE_SENSOR = 7
};

/// Constant 'FAILURE_UNIT_SENSOR_AIRSPEED'.
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_UNIT_SENSOR_AIRSPEED = 8
};

/// Constant 'FAILURE_UNIT_SYSTEM_BATTERY'.
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_UNIT_SYSTEM_BATTERY = 100
};

/// Constant 'FAILURE_UNIT_SYSTEM_MOTOR'.
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_UNIT_SYSTEM_MOTOR = 101
};

/// Constant 'FAILURE_UNIT_SYSTEM_SERVO'.
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_UNIT_SYSTEM_SERVO = 102
};

/// Constant 'FAILURE_UNIT_SYSTEM_AVOIDANCE'.
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_UNIT_SYSTEM_AVOIDANCE = 103
};

/// Constant 'FAILURE_UNIT_SYSTEM_RC_SIGNAL'.
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_UNIT_SYSTEM_RC_SIGNAL = 104
};

/// Constant 'FAILURE_UNIT_SYSTEM_MAVLINK_SIGNAL'.
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_UNIT_SYSTEM_MAVLINK_SIGNAL = 105
};

/// Constant 'FAILURE_TYPE_OK'.
/**
  * Tipos de assinatura de falha a serem injetadas no comportamento do componente alvo selecionado
  * Retorna o componente ao comportamento operacional normal
 */
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_TYPE_OK = 0
};

/// Constant 'FAILURE_TYPE_OFF'.
/**
  * Simula desligamento completo ou perda total de comunicação com o dispositivo
 */
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_TYPE_OFF = 1
};

/// Constant 'FAILURE_TYPE_STUCK'.
/**
  * Trava a leitura do sensor no último valor válido lido antes da falha
 */
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_TYPE_STUCK = 2
};

/// Constant 'FAILURE_TYPE_GARBAGE'.
/**
  * Injeta ruído aleatório de alta frequência inviabilizando o uso dos dados pelo EKF2
 */
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_TYPE_GARBAGE = 3
};

/// Constant 'FAILURE_TYPE_WRONG'.
/**
  * Aplica um offset estático constante corrompendo a calibração do sensor
 */
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_TYPE_WRONG = 4
};

/// Constant 'FAILURE_TYPE_SLOW'.
/**
  * Reduz a taxa de atualização drástica do componente simulando sobrecarga de barramento
 */
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_TYPE_SLOW = 5
};

/// Constant 'FAILURE_TYPE_DELAYED'.
/**
  * Introduz um atraso temporal fixo na chegada das leituras ao estimador
 */
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_TYPE_DELAYED = 6
};

/// Constant 'FAILURE_TYPE_INTERMITTENT'.
/**
  * Alterna o funcionamento aleatoriamente entre operacional e em falha
 */
enum
{
  px4_msgs__msg__VehicleCommand__FAILURE_TYPE_INTERMITTENT = 7
};

/// Constant 'SPEED_TYPE_AIRSPEED'.
/**
  * Tipos de referência de velocidade para o comando VEHICLE_CMD_DO_CHANGE_SPEED (Injetado via param1)
  * Velocidade relativa ao ar (Crucial para sustentação aerodinâmica de asas fixas)
 */
enum
{
  px4_msgs__msg__VehicleCommand__SPEED_TYPE_AIRSPEED = 0
};

/// Constant 'SPEED_TYPE_GROUNDSPEED'.
/**
  * Velocidade real em relação ao solo obtida via GPS/Filtro
 */
enum
{
  px4_msgs__msg__VehicleCommand__SPEED_TYPE_GROUNDSPEED = 1
};

/// Constant 'SPEED_TYPE_CLIMB_SPEED'.
/**
  * Velocidade vertical positiva de subida
 */
enum
{
  px4_msgs__msg__VehicleCommand__SPEED_TYPE_CLIMB_SPEED = 2
};

/// Constant 'SPEED_TYPE_DESCEND_SPEED'.
/**
  * Velocidade vertical negativa de descida
 */
enum
{
  px4_msgs__msg__VehicleCommand__SPEED_TYPE_DESCEND_SPEED = 3
};

/// Constant 'ORBIT_YAW_BEHAVIOUR_HOLD_FRONT_TO_CIRCLE_CENTER'.
/**
  * Comportamento de orientação do Yaw durante a execução do comando de órbita (Injetado via param3)
  * Mantém o nariz do drone apontado fixamente para o centro da órbita
 */
enum
{
  px4_msgs__msg__VehicleCommand__ORBIT_YAW_BEHAVIOUR_HOLD_FRONT_TO_CIRCLE_CENTER = 0
};

/// Constant 'ORBIT_YAW_BEHAVIOUR_HOLD_INITIAL_HEADING'.
/**
  * Trava a proa no ângulo que estava no momento do início do comando
 */
enum
{
  px4_msgs__msg__VehicleCommand__ORBIT_YAW_BEHAVIOUR_HOLD_INITIAL_HEADING = 1
};

/// Constant 'ORBIT_YAW_BEHAVIOUR_UNCONTROLLED'.
/**
  * Desativa o controle de guinada automático deixando o Yaw livre
 */
enum
{
  px4_msgs__msg__VehicleCommand__ORBIT_YAW_BEHAVIOUR_UNCONTROLLED = 2
};

/// Constant 'ORBIT_YAW_BEHAVIOUR_HOLD_FRONT_TANGENT_TO_CIRCLE'.
/**
  * Alinha o nariz do drone tangencialmente apontando para a direção do movimento
 */
enum
{
  px4_msgs__msg__VehicleCommand__ORBIT_YAW_BEHAVIOUR_HOLD_FRONT_TANGENT_TO_CIRCLE = 3
};

/// Constant 'ORBIT_YAW_BEHAVIOUR_RC_CONTROLLED'.
/**
  * Permite que o piloto altere o Yaw manualmente via rádio sem quebrar a trajetória
 */
enum
{
  px4_msgs__msg__VehicleCommand__ORBIT_YAW_BEHAVIOUR_RC_CONTROLLED = 4
};

/// Constant 'ORBIT_YAW_BEHAVIOUR_UNCHANGED'.
/**
  * Mantém o comportamento de orientação de Yaw configurado anteriormente no sistema
 */
enum
{
  px4_msgs__msg__VehicleCommand__ORBIT_YAW_BEHAVIOUR_UNCHANGED = 5
};

/// Constant 'ARMING_ACTION_DISARM'.
/**
  * Ações básicas de armamento (Injetado via param1 em VEHICLE_CMD_COMPONENT_ARM_DISARM)
 */
enum
{
  px4_msgs__msg__VehicleCommand__ARMING_ACTION_DISARM = 0
};

/// Constant 'ARMING_ACTION_ARM'.
enum
{
  px4_msgs__msg__VehicleCommand__ARMING_ACTION_ARM = 1
};

/// Constant 'GRIPPER_ACTION_RELEASE'.
/**
  * Ações de controle de garras físicas de carga (Injetado via param2 em VEHICLE_CMD_DO_GRIPPER)
  * Abre o mecanismo liberando o objeto preso
 */
enum
{
  px4_msgs__msg__VehicleCommand__GRIPPER_ACTION_RELEASE = 0
};

/// Constant 'GRIPPER_ACTION_GRAB'.
/**
  * Fecha o mecanismo prendendo a carga útil
 */
enum
{
  px4_msgs__msg__VehicleCommand__GRIPPER_ACTION_GRAB = 1
};

/// Constant 'ORB_QUEUE_LENGTH'.
/**
  * Define o tamanho máximo de retenção de mensagens não processadas na fila uORB
 */
enum
{
  px4_msgs__msg__VehicleCommand__ORB_QUEUE_LENGTH = 8
};

/// Constant 'COMPONENT_MODE_EXECUTOR_START'.
/**
  * Endereçamento inicial padrão para executores customizados de modos de voo
 */
enum
{
  px4_msgs__msg__VehicleCommand__COMPONENT_MODE_EXECUTOR_START = 1000
};

/// Struct defined in msg/VehicleCommand in the package px4_msgs.
/**
  * Vehicle Command uORB message. Used for commanding a mission / action / etc.
  * Follows the MAVLink COMMAND_INT / COMMAND_LONG definition.
  *
  * @description Mensagem uORB central para envio de comandos de ação, modos e navegação.
  * Suporta a tradução direta de comandos MAVLink recebidos externamente (Companion/GCS)
  * ou gerados internamente pelo executor de missões do PX4.
 */
typedef struct px4_msgs__msg__VehicleCommand
{
  /// Tempo desde a inicialização do sistema (Time-sync / Epoch interno)
  uint64_t timestamp;
  /// --- DECLARAÇÃO DE VARIÁVEIS DO PAYLOAD REAIS DA MENSAGEM ---
  /// Parâmetro genérico 1 (Geralmente dados de controle, configurações e flags de sub-enums)
  float param1;
  /// Parâmetro genérico 2 (Geralmente tempos de integração, ganhos secundários ou velocidades)
  float param2;
  /// Parâmetro genérico 3 (Geralmente raios de órbita, limites dinâmicos ou direções de giro)
  float param3;
  /// Parâmetro genérico 4 (Geralmente ângulos de orientação, atitudes de Yaw e máscaras de bits)
  float param4;
  /// Parâmetro genérico 5 - Alta Precisão (Usado para transporte de coordenadas de Latitude global)
  double param5;
  /// Parâmetro genérico 6 - Alta Precisão (Usado para transporte de coordenadas de Longitude global)
  double param6;
  /// Parâmetro genérico 7 (Usado para transporte de altitudes ou parâmetros flutuantes finais)
  float param7;
  /// Identificador Numérico de Comando Executável (Corresponde aos IDs VEHICLE_CMD_*)
  uint32_t command;
  /// Identificação do MAVLink System ID destino do comando
  uint8_t target_system;
  /// Identificação do MAVLink Component ID destino (0 envia em broadcast para todas as placas/periféricos)
  uint8_t target_component;
  /// Identificação do MAVLink System ID de quem gerou a mensagem (Ex: ID da Raspberry Pi)
  uint8_t source_system;
  /// Identificação do MAVLink Component ID / Executor de modo de quem originou o envio
  uint16_t source_component;
  /// Contador de pacotes de confirmação (0 para envio inicial, incrementos sequenciais para reenvios críticos)
  uint8_t confirmation;
  /// Flag de auditoria de segurança (Define se a origem é um link externo MAVLink ou nativa interna)
  bool from_external;
} px4_msgs__msg__VehicleCommand;

// Struct for a sequence of px4_msgs__msg__VehicleCommand.
typedef struct px4_msgs__msg__VehicleCommand__Sequence
{
  px4_msgs__msg__VehicleCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__msg__VehicleCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PX4_MSGS__MSG__DETAIL__VEHICLE_COMMAND__STRUCT_H_
