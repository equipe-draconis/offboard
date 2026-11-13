// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from px4_msgs:msg/VehicleCommand.idl
// generated code does not contain a copyright notice

#include "px4_msgs/msg/detail/vehicle_command__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_px4_msgs
const rosidl_type_hash_t *
px4_msgs__msg__VehicleCommand__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1f, 0x0a, 0xb5, 0x37, 0x80, 0x7e, 0x2e, 0x20,
      0xe0, 0x48, 0x26, 0x63, 0x3e, 0xa2, 0xc5, 0x2e,
      0x54, 0x31, 0xbe, 0xa8, 0xeb, 0x01, 0x87, 0x15,
      0x2f, 0xf2, 0x3b, 0xd0, 0x7f, 0x1d, 0xd3, 0x0b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char px4_msgs__msg__VehicleCommand__TYPE_NAME[] = "px4_msgs/msg/VehicleCommand";

// Define type names, field names, and default values
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__timestamp[] = "timestamp";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__param1[] = "param1";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__param2[] = "param2";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__param3[] = "param3";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__param4[] = "param4";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__param5[] = "param5";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__param6[] = "param6";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__param7[] = "param7";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__command[] = "command";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__target_system[] = "target_system";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__target_component[] = "target_component";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__source_system[] = "source_system";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__source_component[] = "source_component";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__confirmation[] = "confirmation";
static char px4_msgs__msg__VehicleCommand__FIELD_NAME__from_external[] = "from_external";

static rosidl_runtime_c__type_description__Field px4_msgs__msg__VehicleCommand__FIELDS[] = {
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__timestamp, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__param1, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__param2, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__param3, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__param4, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__param5, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__param6, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__param7, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__command, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__target_system, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__target_component, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__source_system, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__source_component, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__confirmation, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleCommand__FIELD_NAME__from_external, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
px4_msgs__msg__VehicleCommand__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {px4_msgs__msg__VehicleCommand__TYPE_NAME, 27, 27},
      {px4_msgs__msg__VehicleCommand__FIELDS, 15, 15},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Vehicle Command uORB message. Used for commanding a mission / action / etc.\n"
  "# Follows the MAVLink COMMAND_INT / COMMAND_LONG definition.\n"
  "#\n"
  "# @description Mensagem uORB central para envio de comandos de a\\xc3\\xa7\\xc3\\xa3o, modos e navega\\xc3\\xa7\\xc3\\xa3o.\n"
  "# Suporta a tradu\\xc3\\xa7\\xc3\\xa3o direta de comandos MAVLink recebidos externamente (Companion/GCS)\n"
  "# ou gerados internamente pelo executor de miss\\xc3\\xb5es do PX4.\n"
  "\n"
  "uint32 MESSAGE_VERSION = 0\n"
  "\n"
  "uint64 timestamp                   # [us] Tempo desde a inicializa\\xc3\\xa7\\xc3\\xa3o do sistema (Time-sync / Epoch interno)\n"
  "\n"
  "# --- COMANDOS CUSTOMIZADOS E DE TESTE ---\n"
  "uint16 VEHICLE_CMD_CUSTOM_0 = 0    # Comando customizado de teste 0\n"
  "uint16 VEHICLE_CMD_CUSTOM_1 = 1    # Comando customizado de teste 1\n"
  "uint16 VEHICLE_CMD_CUSTOM_2 = 2    # Comando customizado de teste 2\n"
  "\n"
  "# --- COMANDOS DE NAVEGA\\xc3\\x87\\xc3\\x83O E MISS\\xc3\\x83O (NAV_*) ---\n"
  "# param1: Tempo de espera [s] (ignorado por asa fixa, tempo pairando para multirotores)\n"
  "# param2: Raio de aceita\\xc3\\xa7\\xc3\\xa3o [m] (se atingido dentro da esfera, o waypoint \\xc3\\xa9 considerado alcan\\xc3\\xa7ado)\n"
  "# param3: Raio de passagem [m] (0 para passar direto. >0 \\xc3\\xb3rbita hor\\xc3\\xa1ria, <0 \\xc3\\xb3rbita anti-hor\\xc3\\xa1ria)\n"
  "# param4: \\xc3\\x82ngulo de Yaw desejado no waypoint (multirotores)\n"
  "# param5 (double): Latitude do destino (WGS-84)\n"
  "# param6 (double): Longitude do destino (WGS-84)\n"
  "# param7: Altitude do destino (AMSL)\n"
  "uint16 VEHICLE_CMD_NAV_WAYPOINT = 16\n"
  "\n"
  "# param3: Raio ao redor do ponto [m] (>0 hor\\xc3\\xa1rio, <0 anti-hor\\xc3\\xa1rio)\n"
  "# param4: \\xc3\\x82ngulo de Yaw desejado\n"
  "# param5/6/7: Coordenadas globais de Loiter (Lat/Lon/Alt)\n"
  "uint16 VEHICLE_CMD_NAV_LOITER_UNLIM = 17 # Mant\\xc3\\xa9m Loiter no ponto por tempo ilimitado\n"
  "uint16 VEHICLE_CMD_NAV_LOITER_TURNS = 18 # Mant\\xc3\\xa9m Loiter no ponto por X voltas (param1 = Voltas)\n"
  "uint16 VEHICLE_CMD_NAV_LOITER_TIME  = 19 # Mant\\xc3\\xa9m Loiter no ponto por X segundos (param1 = Segundos)\n"
  "\n"
  "uint16 VEHICLE_CMD_NAV_RETURN_TO_LAUNCH = 20 # Executa a rotina de Retorno ao Ponto de Decolagem (RTL)\n"
  "\n"
  "# param4: \\xc3\\x82ngulo de Yaw desejado no pouso\n"
  "# param5/6/7: Coordenadas globais do pouso (Lat/Lon/Alt)\n"
  "uint16 VEHICLE_CMD_NAV_LAND = 21\n"
  "\n"
  "# param1: Pitch m\\xc3\\xadnimo de decolagem (apenas asa fixa)\n"
  "# param4: \\xc3\\x82ngulo de Yaw em graus [0,360] no referencial NED\n"
  "# param5/6/7: Coordenadas globais de decolagem (Lat/Lon/Alt)\n"
  "uint16 VEHICLE_CMD_NAV_TAKEOFF = 22\n"
  "\n"
  "uint16 VEHICLE_CMD_NAV_PRECLAND = 23 # Inicia pouso de precis\\xc3\\xa3o baseado em sensores (IR, tags, vis\\xc3\\xa3o)\n"
  "\n"
  "# param1: Raio da \\xc3\\xb3rbita [m]\n"
  "# param2: Velocidade tangencial [m/s]\n"
  "# param3: Comportamento do Yaw durante a \\xc3\\xb3rbita (ver sub-enum ORBIT_YAW_BEHAVIOUR)\n"
  "# param5/6/7: Coordenadas do centro da \\xc3\\xb3rbita (X/Y/Z ou Lat/Lon/Alt)\n"
  "uint16 VEHICLE_CMD_DO_ORBIT = 34\n"
  "\n"
  "# param1: Raio Maior [m]\n"
  "# param2: Raio Menor [m]\n"
  "# param3: Velocidade de avan\\xc3\\xa7o [m/s]\n"
  "# param4: Orienta\\xc3\\xa7\\xc3\\xa3o angular do padr\\xc3\\xa3o\n"
  "# param5/6/7: Coordenadas do centro do padr\\xc3\\xa3o (Lat/Lon/Alt)\n"
  "uint16 VEHICLE_CMD_DO_FIGUREEIGHT = 35\n"
  "\n"
  "# param1: Modo de Regi\\xc3\\xa3o de Interesse (ver sub-enum VEHICLE_ROI)\n"
  "# param2: \\xc3\\x8dndice da miss\\xc3\\xa3o ou ID do alvo rastreado\n"
  "# param3: \\xc3\\x8dndice do ROI (permite gerenciar m\\xc3\\xbaltiplos alvos)\n"
  "# param5/6/7: Coordenadas de foco do ROI fixo (X/Y/Z)\n"
  "uint16 VEHICLE_CMD_NAV_ROI = 80\n"
  "\n"
  "# param1: Obstacle Avoidance Local (0:Desativa, 1:Ativa, 2:Ativa e reseta mapa)\n"
  "# param2: Path Planning Global (0:Desativa, 1:Ativa, 2:Ativa e reseta grid, 3:Ativa e reseta rota)\n"
  "# param4: \\xc3\\x82ngulo de Yaw final desejado no objetivo [0,360]\n"
  "# param5/6/7: Coordenadas globais do objetivo final (Lat/Lon/Alt)\n"
  "uint16 VEHICLE_CMD_NAV_PATHPLANNING = 81\n"
  "\n"
  "# Comandos espec\\xc3\\xadficos para aeronaves VTOL (Transi\\xc3\\xa7\\xc3\\xa3o de asa fixa / multirotor)\n"
  "uint16 VEHICLE_CMD_NAV_VTOL_TAKEOFF = 84 # Decolagem vertical seguida de transi\\xc3\\xa7\\xc3\\xa3o para asa fixa\n"
  "uint16 VEHICLE_CMD_NAV_VTOL_LAND    = 85 # Transi\\xc3\\xa7\\xc3\\xa3o para multirotor seguida de pouso vertical\n"
  "\n"
  "# param1: Timeout de controle externo [s] (0 = sem timeout)\n"
  "# param2: Altitude m\\xc3\\xadnima absoluta AMSL [m] (se violada, aborta e retoma miss\\xc3\\xa3o)\n"
  "# param3: Altitude m\\xc3\\xa1xima absoluta AMSL [m] (se violada, aborta e retoma miss\\xc3\\xa3o)\n"
  "# param4: Raio de movimento horizontal m\\xc3\\xa1ximo [m] medido a partir da execu\\xc3\\xa7\\xc3\\xa3o do comando\n"
  "uint16 VEHICLE_CMD_NAV_GUIDED_LIMITS = 90 # Define limites geogr\\xc3\\xa1ficos de seguran\\xc3\\xa7a para controle externo (Offboard)\n"
  "\n"
  "# param1: System ID do controlador mestre\n"
  "# param2: Component ID do controlador mestre\n"
  "uint16 VEHICLE_CMD_NAV_GUIDED_MASTER = 91\n"
  "\n"
  "# param1: Delay de execu\\xc3\\xa7\\xc3\\xa3o [s] (-1 para habilitar os campos de hor\\xc3\\xa1rio UTC nos params seguintes)\n"
  "# param2: Hora UTC [0-23] (-1 para ignorar)\n"
  "# param3: Minuto UTC [0-59] (-1 para ignorar)\n"
  "# param4: Segundo UTC [0-59]\n"
  "uint16 VEHICLE_CMD_NAV_DELAY = 93\n"
  "\n"
  "uint16 VEHICLE_CMD_NAV_LAST = 95 # NOP - Marcador de limite superior para comandos do tipo NAV\n"
  "\n"
  "# --- COMANDOS CONDICIONAIS DE MISS\\xc3\\x83O (CONDITION_*) ---\n"
  "uint16 VEHICLE_CMD_CONDITION_DELAY      = 112 # Pausa a m\\xc3\\xa1quina de estados da miss\\xc3\\xa3o por X segundos (param1)\n"
  "uint16 VEHICLE_CMD_CONDITION_CHANGE_ALT = 113 # Altera altitude na taxa de param1 [m/s]. Segura miss\\xc3\\xa3o at\\xc3\\xa9 atingir param7 (Alt final)\n"
  "uint16 VEHICLE_CMD_CONDITION_DISTANCE   = 114 # Segura miss\\xc3\\xa3o at\\xc3\\xa9 que a dist\\xc3\\xa2ncia ao pr\\xc3\\xb3ximo WP seja menor que param1 [m]\n"
  "\n"
  "# param1: \\xc3\\x82ngulo alvo [0,360] (0 = Norte)\n"
  "# param2: Velocidade angular do giro [deg/s]\n"
  "# param3: Dire\\xc3\\xa7\\xc3\\xa3o (-1: Anti-hor\\xc3\\xa1rio, 1: Hor\\xc3\\xa1rio)\n"
  "# param4: Tipo de refer\\xc3\\xaancia (0: Absoluto, 1: Relativo ao rumo atual)\n"
  "uint16 VEHICLE_CMD_CONDITION_YAW = 115\n"
  "\n"
  "uint16 VEHICLE_CMD_CONDITION_LAST = 159 # NOP - Marcador de limite superior para comandos condicionais\n"
  "\n"
  "# param1: Modo 2D (0: Ortogonal \\xc3\\xa0 rota planejada)\n"
  "# param2: Modo de altitude (0: Ignora altitude do gate)\n"
  "# param5/6/7: Posi\\xc3\\xa7\\xc3\\xa3o do Gate (Lat/Lon/Alt)\n"
  "uint16 VEHICLE_CMD_CONDITION_GATE = 4501 # Aguarda at\\xc3\\xa9 cruzar um plano limite (Gate)\n"
  "\n"
  "# --- COMANDOS DE A\\xc3\\x87\\xc3\\x83O IMEDIATA (DO_*) ---\n"
  "uint16 VEHICLE_CMD_DO_SET_MODE = 176 # Altera o modo do sistema de acordo com o enum MAV_MODE (param1)\n"
  "\n"
  "# param1: N\\xc3\\xbamero de sequ\\xc3\\xaancia (ID) do item da miss\\xc3\\xa3o alvo\n"
  "# param2: Contagem de repeti\\xc3\\xa7\\xc3\\xb5es do ciclo\n"
  "uint16 VEHICLE_CMD_DO_JUMP = 177\n"
  "\n"
  "# param1: Tipo de velocidade (0: Airspeed, 1: Groundspeed, 2: Climb, 3: Descend)\n"
  "# param2: Velocidade alvo [m/s] (-1 para manter inalterado)\n"
  "# param3: Acelera\\xc3\\xa7\\xc3\\xa3o/Throttle em porcentagem [%] (-1 para manter inalterado)\n"
  "uint16 VEHICLE_CMD_DO_CHANGE_SPEED = 178\n"
  "\n"
  "# param1: Escolha da refer\\xc3\\xaancia (1: Usa posi\\xc3\\xa7\\xc3\\xa3o atual do GPS, 0: Usa coordenadas dos params 5/6/7)\n"
  "uint16 VEHICLE_CMD_DO_SET_HOME = 179\n"
  "\n"
  "# param1: ID num\\xc3\\xa9rico mapeado do par\\xc3\\xa2metro interno do firmware\n"
  "# param2: Valor a ser injetado no par\\xc3\\xa2metro\n"
  "uint16 VEHICLE_CMD_DO_SET_PARAMETER = 180\n"
  "\n"
  "# param1: N\\xc3\\xbamero identificador do rel\\xc3\\xa9 f\\xc3\\xadsico (GPIO Out)\n"
  "# param2: Estado (1: Ligado, 0: Desligado)\n"
  "uint16 VEHICLE_CMD_DO_SET_RELAY = 181\n"
  "\n"
  "# param1: ID do rel\\xc3\\xa9 | param2: Ciclos de repeti\\xc3\\xa7\\xc3\\xa3o | param3: Per\\xc3\\xadodo do ciclo [s]\n"
  "uint16 VEHICLE_CMD_DO_REPEAT_RELAY = 182\n"
  "\n"
  "# param1: Canal do Servo | param2: Pulso PWM [us] (Ex: 1000 a 2000) | param3: Ciclos | param4: Tempo [s]\n"
  "uint16 VEHICLE_CMD_DO_REPEAT_SERVO = 184\n"
  "\n"
  "uint16 VEHICLE_CMD_DO_FLIGHTTERMINATION = 185 # Ativa termina\\xc3\\xa7\\xc3\\xa3o for\\xc3\\xa7ada de voo imediatamente (Corte de motores/Paraquedas) se param1 > 0.5\n"
  "\n"
  "# param1: Altitude alvo | param2: Frame de refer\\xc3\\xaancia da altitude\n"
  "uint16 VEHICLE_CMD_DO_CHANGE_ALTITUDE = 186\n"
  "\n"
  "# param1 a param6: Valores de controle direto para as sa\\xc3\\xaddas de atuadores 1 a 6 | param7: \\xc3\\x8dndice do grupo\n"
  "uint16 VEHICLE_CMD_DO_SET_ACTUATOR = 187\n"
  "\n"
  "# param5/6: Coordenadas aproximadas para busca do circuito de pouso mais pr\\xc3\\xb3ximo na miss\\xc3\\xa3o\n"
  "uint16 VEHICLE_CMD_DO_LAND_START = 189\n"
  "\n"
  "uint16 VEHICLE_CMD_DO_GO_AROUND = 191 # Comando de arremetida (Go-Around) para abortar pouso aut\\xc3\\xb4nomo com seguran\\xc3\\xa7a. param1 = Altitude de escape\n"
  "\n"
  "# param1: Velocidade de aproxima\\xc3\\xa7\\xc3\\xa3o [m/s] | param2: Bitmask de eixos | param3: Raio loiter (asa fixa) | param4: Yaw desejado\n"
  "# param5/6/7: Coordenadas espaciais do novo alvo de posicionamento (Lat/Lon/Alt)\n"
  "uint16 VEHICLE_CMD_DO_REPOSITION = 192\n"
  "\n"
  "uint16 VEHICLE_CMD_DO_PAUSE_CONTINUE = 193 # Alterna estados de pausa e retomada de miss\\xc3\\xb5es ou trajet\\xc3\\xb3rias autom\\xc3\\xa1ticas\n"
  "\n"
  "# Comandos de apontamento est\\xc3\\xa1tico do sensor/c\\xc3\\xa2mera (ROI)\n"
  "uint16 VEHICLE_CMD_DO_SET_ROI_LOCATION     = 195 # Aponta c\\xc3\\xa2mera para localiza\\xc3\\xa7\\xc3\\xa3o fixa (param5/6/7)\n"
  "uint16 VEHICLE_CMD_DO_SET_ROI_WPNEXT_OFFSET = 196 # Aponta c\\xc3\\xa2mera para o pr\\xc3\\xb3ximo WP aplicando offsets em param5(Pitch), param6(Roll) e param7(Yaw)\n"
  "uint16 VEHICLE_CMD_DO_SET_ROI_NONE          = 197 # Cancela rastreamento de ROI atual e retorna sensores para a orienta\\xc3\\xa7\\xc3\\xa3o padr\\xc3\\xa3o\n"
  "\n"
  "# param1: ID da C\\xc3\\xa2mera (-1 = todas) | param2: Transmiss\\xc3\\xa3o (0: off, 1: compresso, 2: raw) | param3: Modo (0: streaming, >0: captura a cada N s) | param4: Grava\\xc3\\xa7\\xc3\\xa3o\n"
  "uint16 VEHICLE_CMD_DO_CONTROL_VIDEO = 200\n"
  "\n"
  "uint16 VEHICLE_CMD_DO_SET_ROI       = 201 # Controle gen\\xc3\\xa9rico de ROI (id\\xc3\\xaantico ao VEHICLE_CMD_NAV_ROI, mas de execu\\xc3\\xa7\\xc3\\xa3o imediata)\n"
  "uint16 VEHICLE_CMD_DO_DIGICAM_CONTROL = 203 # Gatilho direto de controle legado para c\\xc3\\xa2meras digitais\n"
  "\n"
  "# param1: Modo de opera\\xc3\\xa7\\xc3\\xa3o do Mount (ver sub-enum MAV_MOUNT_MODE)\n"
  "# param2: Ativa estabiliza\\xc3\\xa7\\xc3\\xa3o de Roll (1: sim, 0: n\\xc3\\xa3o) | param3: Estabiliza\\xc3\\xa7\\xc3\\xa3o de Pitch | param4: Estabiliza\\xc3\\xa7\\xc3\\xa3o de Yaw\n"
  "uint16 VEHICLE_CMD_DO_MOUNT_CONFIGURE = 204\n"
  "\n"
  "# param1: Pitch/Lat | param2: Roll/Lon | param3: Yaw/Alt (depende do modo de opera\\xc3\\xa7\\xc3\\xa3o definido no param7)\n"
  "uint16 VEHICLE_CMD_DO_MOUNT_CONTROL = 205\n"
  "\n"
  "uint16 VEHICLE_CMD_DO_SET_CAM_TRIGG_DIST = 206 # Configura disparo de c\\xc3\\xa2mera por dist\\xc3\\xa2ncia m\\xc3\\xa9trica espacial percorrida (param1 = Dist\\xc3\\xa2ncia [m])\n"
  "uint16 VEHICLE_CMD_DO_FENCE_ENABLE      = 207 # Ativa ou desativa cercas geogr\\xc3\\xa1ficas virtuais / Geofence (param1: 1=Ativa, 0=Desativa)\n"
  "uint16 VEHICLE_CMD_DO_PARACHUTE          = 208 # Controle manual de eje\\xc3\\xa7\\xc3\\xa3o do paraquedas (param1: ver sub-enum PARACHUTE_ACTION)\n"
  "\n"
  "# param1: ID/Inst\\xc3\\xa2ncia do motor | param2: Tipo de comando de acelera\\xc3\\xa7\\xc3\\xa3o | param3: Valor do throttle | param4: Timeout [s]\n"
  "uint16 VEHICLE_CMD_DO_MOTOR_TEST   = 209\n"
  "uint16 VEHICLE_CMD_DO_INVERTED_FLIGHT = 210 # For\\xc3\\xa7a voo invertido em aeronaves homologadas (param1: 1=Invertido, 0=Normal)\n"
  "uint16 VEHICLE_CMD_DO_GRIPPER         = 211 # Acionamento de garras de carga/servos de libera\\xc3\\xa7\\xc3\\xa3o (ver sub-enum GRIPPER_ACTION)\n"
  "uint16 VEHICLE_CMD_DO_SET_CAM_TRIGG_INTERVAL = 214 # Configura disparo de c\\xc3\\xa2mera baseado em intervalos fixos de tempo (param1 = Intervalo [ms])\n"
  "\n"
  "# Controle de gimbals tridimensionais usando quat\\xc3\\xa9rnios de atitude espacial diretos (param1=qw, param2=qx, param3=qy, param4=qz)\n"
  "uint16 VEHICLE_CMD_DO_MOUNT_CONTROL_QUAT = 220\n"
  "\n"
  "uint16 VEHICLE_CMD_DO_GUIDED_MASTER = 221 # Duplicata operacional imediata do comando NAV_GUIDED_MASTER\n"
  "uint16 VEHICLE_CMD_DO_GUIDED_LIMITS = 222 # Duplicata operacional imediata do comando NAV_GUIDED_LIMITS\n"
  "uint16 VEHICLE_CMD_DO_LAST          = 240 # NOP - Marcador de limite superior para blocos operacionais de a\\xc3\\xa7\\xc3\\xa3o imediata\n"
  "\n"
  "# --- PROCESSOS DE PR\\xc3\\x89-VOO E MANUTEN\\xc3\\x87\\xc3\\x83O (PREFLIGHT_*) ---\n"
  "uint16 VEHICLE_CMD_PREFLIGHT_CALIBRATION            = 241 # Executa calibra\\xc3\\xa7\\xc3\\xa3o geral de sensores (Aceito apenas em solo/disarmed)\n"
  "uint16 PREFLIGHT_CALIBRATION_TEMPERATURE_CALIBRATION = 3   # Sub-par\\xc3\\xa2metro injetado em param1 para iniciar calibra\\xc3\\xa7\\xc3\\xa3o t\\xc3\\xa9rmica de sensores\n"
  "\n"
  "# param1: Sensor alvo (0:giros, 1:aceler\\xc3\\xb4metros, 2:magnet\\xc3\\xb4metro, 3:bar\\xc3\\xb4metro, 4:optical flow)\n"
  "# param2/3/4: Offsets brutos para os eixos X, Y e Z nas unidades nativas do sensor alvo\n"
  "uint16 VEHICLE_CMD_PREFLIGHT_SET_SENSOR_OFFSETS = 242\n"
  "\n"
  "uint16 VEHICLE_CMD_PREFLIGHT_UAVCAN             = 243 # Dispara mapeamento din\\xc3\\xa2mico de n\\xc3\\xb3s atuadores via barramento CAN/UAVCAN (param1=1 inicia)\n"
  "\n"
  "# param1: Controle de par\\xc3\\xa2metros (0: L\\xc3\\xaa da Flash/EEPROM, 1: Grava par\\xc3\\xa2metros atuais na Flash)\n"
  "# param2: Controle de miss\\xc3\\xb5es (0: L\\xc3\\xaa da Flash/EEPROM, 1: Grava miss\\xc3\\xa3o atual na Flash)\n"
  "uint16 VEHICLE_CMD_PREFLIGHT_STORAGE            = 245\n"
  "\n"
  "# param1: Piloto Autom\\xc3\\xa1tico (0: NOP, 1: Reboot PX4, 2: Shutdown PX4)\n"
  "# param2: Companion Computer / OBC (0: NOP, 1: Reboot Raspberry/Odroid, 2: Shutdown OBC)\n"
  "uint16 VEHICLE_CMD_PREFLIGHT_REBOOT_SHUTDOWN    = 246\n"
  "\n"
  "# Controle de levantamentos aerofotogram\\xc3\\xa9tricos obl\\xc3\\xadquos (Mapeamento 3D complexo de fachadas)\n"
  "uint16 VEHICLE_CMD_OBLIQUE_SURVEY           = 260\n"
  "uint16 VEHICLE_CMD_DO_SET_STANDARD_MODE     = 262 # For\\xc3\\xa7a o acionamento de modos padr\\xc3\\xa3o MAVLink estruturados\n"
  "uint16 VEHICLE_CMD_GIMBAL_DEVICE_INFORMATION = 283 # Requisita metadados estruturados de recursos e vers\\xc3\\xa3o de hardware do gimbal conectado\n"
  "\n"
  "# --- FLUXO PRINCIPAL E GERENCIAMENTO DE HARDWARE ---\n"
  "# param1: ID do item inicial da miss\\xc3\\xa3o onde o sequenciador deve come\\xc3\\xa7ar\n"
  "# param2: ID do item final onde a miss\\xc3\\xa3o ser\\xc3\\xa1 dada por encerrada automaticamente\n"
  "uint16 VEHICLE_CMD_MISSION_START = 300\n"
  "\n"
  "uint16 VEHICLE_CMD_ACTUATOR_TEST   = 310 # Executa movimenta\\xc3\\xa7\\xc3\\xa3o de teste de atuadores individuais (param1=Valor [-1,1], param2=Timeout [s])\n"
  "uint16 VEHICLE_CMD_CONFIGURE_ACTUATOR = 311 # Envia diretivas em tempo real de reconfigura\\xc3\\xa7\\xc3\\xa3o de fun\\xc3\\xa7\\xc3\\xb5es das sa\\xc3\\xaddas f\\xc3\\xadsicas\n"
  "\n"
  "# param1: Estado de armamento desejado (1: Armar motores, 0: Desarmar sistema de propuls\\xc3\\xa3o)\n"
  "uint16 VEHICLE_CMD_COMPONENT_ARM_DISARM = 400\n"
  "\n"
  "uint16 VEHICLE_CMD_RUN_PREARM_CHECKS = 401 # For\\xc3\\xa7a a re-execu\\xc3\\xa7\\xc3\\xa3o imediata dos testes internos de seguran\\xc3\\xa7a pr\\xc3\\xa9-armamento (Pre-flight safety checks)\n"
  "uint16 VEHICLE_CMD_INJECT_FAILURE     = 420 # Injeta falhas de hardware via software para testes de redund\\xc3\\xa2ncia (SITL/HITL)\n"
  "\n"
  "# Inicializa pareamento de receptores de r\\xc3\\xa1dio RC (param1: 0=Spektrum | param2: 0=DSM2, 1=DSMX)\n"
  "uint16 VEHICLE_CMD_START_RX_PAIR = 500\n"
  "\n"
  "uint16 VEHICLE_CMD_REQUEST_MESSAGE             = 512 # Solicita envio pontual de uma inst\\xc3\\xa2ncia de mensagem uORB/MAVLink espec\\xc3\\xadfica\n"
  "uint16 VEHICLE_CMD_REQUEST_CAMERA_INFORMATION = 521 # Requisita dados estruturados est\\xc3\\xa1ticos de capacidades da c\\xc3\\xa2mera (CAMERA_INFORMATION)\n"
  "uint16 VEHICLE_CMD_SET_CAMERA_MODE             = 530 # Alterna modos internos de captura da c\\xc3\\xa2mera (Ex: Modo foto vs Modo grava\\xc3\\xa7\\xc3\\xa3o de v\\xc3\\xaddeo)\n"
  "uint16 VEHICLE_CMD_SET_CAMERA_ZOOM             = 531 # Controla n\\xc3\\xadvel de zoom \\xc3\\xb3tico/digital da c\\xc3\\xa2mera embarcada\n"
  "uint16 VEHICLE_CMD_SET_CAMERA_FOCUS            = 532 # Ajusta foco (manual/autom\\xc3\\xa1tico) das lentes do payload \\xc3\\xb3ptico\n"
  "\n"
  "# Controle avan\\xc3\\xa7ado e arbitragem de gimbals de c\\xc3\\xa2mera via arquitetura Gimbal Manager do MAVLink v2\n"
  "uint16 VEHICLE_CMD_DO_GIMBAL_MANAGER_PITCHYAW   = 1000 # Envia setpoints diretos de malha fechada de Pitch e Yaw ao gerenciador do Gimbal\n"
  "uint16 VEHICLE_CMD_DO_GIMBAL_MANAGER_CONFIGURE  = 1001 # Define hierarquia e prioridades de controle (SysID/CompID prim\\xc3\\xa1rio vs secund\\xc3\\xa1rio)\n"
  "\n"
  "uint16 VEHICLE_CMD_IMAGE_START_CAPTURE = 2000 # Inicia disparo sequencial de captura de fotos\n"
  "uint16 VEHICLE_CMD_DO_TRIGGER_CONTROL  = 2003 # Habilita ou desabilita o subsistema f\\xc3\\xadsico automatizado de trigger de c\\xc3\\xa2mera do PX4\n"
  "uint16 VEHICLE_CMD_VIDEO_START_CAPTURE = 2500 # Inicia grava\\xc3\\xa7\\xc3\\xa3o cont\\xc3\\xadnua de fluxo de v\\xc3\\xaddeo digital\n"
  "uint16 VEHICLE_CMD_VIDEO_STOP_CAPTURE  = 2501 # Interrompe grava\\xc3\\xa7\\xc3\\xa3o de fluxo de v\\xc3\\xaddeo e fecha o arquivo gerado\n"
  "uint16 VEHICLE_CMD_LOGGING_START       = 2510 # Inicia a transmiss\\xc3\\xa3o em tempo real de logs estruturados em formato ULog via link de telemetria\n"
  "uint16 VEHICLE_CMD_LOGGING_STOP        = 2511 # Interrompe a transmiss\\xc3\\xa3o de streaming de ULog ativo\n"
  "uint16 VEHICLE_CMD_CONTROL_HIGH_LATENCY = 2600 # Gerencia o tr\\xc3\\xa1fego e ativa\\xc3\\xa7\\xc3\\xa3o de links de dados de alta lat\\xc3\\xaancia (Ex: Telemetria via Sat\\xc3\\xa9lite/Iridium)\n"
  "uint16 VEHICLE_CMD_DO_VTOL_TRANSITION   = 3000 # For\\xc3\\xa7a a transi\\xc3\\xa7\\xc3\\xa3o manual imediata de estado de voo em VTOL (Multirotor <-> Asa Fixa)\n"
  "uint16 VEHICLE_CMD_ARM_AUTHORIZATION_REQUEST = 3001 # Requisi\\xc3\\xa7\\xc3\\xa3o de valida\\xc3\\xa7\\xc3\\xa3o externa em sistemas com chaves de armamento centralizadas de seguran\\xc3\\xa7a\n"
  "uint16 VEHICLE_CMD_PAYLOAD_PREPARE_DEPLOY    = 30001 # Prepara a m\\xc3\\xa1quina de estados do payload para eje\\xc3\\xa7\\xc3\\xa3o/opera\\xc3\\xa7\\xc3\\xa3o dentro do plano de voo\n"
  "uint16 VEHICLE_CMD_PAYLOAD_CONTROL_DEPLOY    = 30002 # Executa e controla dinamicamente o disparo ou deploy do mecanismo do payload\n"
  "\n"
  "# param5/6: Posi\\xc3\\xa7\\xc3\\xa3o do sensor (se zero, assume posi\\xc3\\xa7\\xc3\\xa3o GPS atual) | param7: Proa/Yaw de refer\\xc3\\xaancia conhecida\n"
  "uint16 VEHICLE_CMD_FIXED_MAG_CAL_YAW = 42006 # Calibra\\xc3\\xa7\\xc3\\xa3o ultra-r\\xc3\\xa1pida de magnet\\xc3\\xb4metro baseada em tabelas magn\\xc3\\xa9ticas globais (WMM) e proa conhecida\n"
  "uint16 VEHICLE_CMD_DO_WINCH          = 42600 # Comanda a opera\\xc3\\xa7\\xc3\\xa3o mec\\xc3\\xa2nica de guinchos/cabos de resgate e entrega de carga\n"
  "\n"
  "# Comandos de corre\\xc3\\xa7\\xc3\\xa3o externa para algoritmos de estima\\xc3\\xa7\\xc3\\xa3o de estado (EKF2) em cen\\xc3\\xa1rios de navega\\xc3\\xa7\\xc3\\xa3o estimada (Dead Reckoning)\n"
  "uint16 VEHICLE_CMD_EXTERNAL_POSITION_ESTIMATE = 43003 # Reseta/Injeta posi\\xc3\\xa7\\xc3\\xa3o global externa estimada no filtro de Kalman\n"
  "uint16 VEHICLE_CMD_EXTERNAL_WIND_ESTIMATE     = 43004 # Injeta vetor de estimativa de vento externo para ajuste de controle aerodin\\xc3\\xa2mico\n"
  "\n"
  "# --- EXTENS\\xc3\\x95ES INTERNAS EXCLUSIVAS DO ECOSSISTEMA PX4 ---\n"
  "uint32 VEHICLE_CMD_PX4_INTERNAL_START = 65537 # Marcador inicial para comandos exclusivos que operam acima do limite de 16-bits do MAVLink\n"
  "\n"
  "# param5/6/7: Coordenadas de origem f\\xc3\\xadsica local (Lat/Lon/Alt AMSL vinda do receptor GNSS)\n"
  "uint32 VEHICLE_CMD_SET_GPS_GLOBAL_ORIGIN = 100000 # Define a origem geogr\\xc3\\xa1fica global absoluta que representar\\xc3\\xa1 o ponto (0,0,0) local do EKF2\n"
  "\n"
  "# param1: Estado de navega\\xc3\\xa7\\xc3\\xa3o alvo mapeado diretamente conforme a m\\xc3\\xa1quina de estados interna do Commander do PX4\n"
  "uint32 VEHICLE_CMD_SET_NAV_STATE = 100001\n"
  "\n"
  "# --- SUB-ENUMERATIONS E M\\xc3\\x81SCARAS DE DADOS PARA PAR\\xc3\\x82METROS ESPEC\\xc3\\x8dFICOS ---\n"
  "\n"
  "# Modos de opera\\xc3\\xa7\\xc3\\xa3o de Gimbal/Mount (Injetados via param1 ou param7 em comandos de Mount)\n"
  "uint8 VEHICLE_MOUNT_MODE_RETRACT           = 0 # Recolhe o gimbal para a posi\\xc3\\xa7\\xc3\\xa3o de prote\\xc3\\xa7\\xc3\\xa3o, desativa estabiliza\\xc3\\xa7\\xc3\\xa3o e desliga motores\n"
  "uint8 VEHICLE_MOUNT_MODE_NEUTRAL           = 1 # Move o gimbal para o centro neutro est\\xc3\\xa1tico alinhado com a estrutura f\\xc3\\xadsica da aeronave\n"
  "uint8 VEHICLE_MOUNT_MODE_MAVLINK_TARGETING = 2 # Transfere o controle dos eixos para setpoints din\\xc3\\xa2micos via MAVLink com estabiliza\\xc3\\xa7\\xc3\\xa3o ativa\n"
  "uint8 VEHICLE_MOUNT_MODE_RC_TARGETING      = 3 # Vincula o controle de apontamento diretamente aos canais mapeados no r\\xc3\\xa1dio controle (RC)\n"
  "uint8 VEHICLE_MOUNT_MODE_GPS_POINT         = 4 # Trava o foco da c\\xc3\\xa2mera apontado fixamente para uma coordenada global (Lat/Lon/Alt)\n"
  "uint8 VEHICLE_MOUNT_MODE_ENUM_END          = 5\n"
  "\n"
  "# Modos de opera\\xc3\\xa7\\xc3\\xa3o de Regi\\xc3\\xa3o de Interesse / ROI (Injetados via param1)\n"
  "uint8 VEHICLE_ROI_NONE     = 0 # Cancela foco em alvos, sensores retornam para comportamento padr\\xc3\\xa3o de voo\n"
  "uint8 VEHICLE_ROI_WPNEXT   = 1 # Mant\\xc3\\xa9m os sensores apontados continuamente na dire\\xc3\\xa7\\xc3\\xa3o do pr\\xc3\\xb3ximo waypoint da rota\n"
  "uint8 VEHICLE_ROI_WPINDEX  = 2 # Trava o apontamento dos sensores para um waypoint espec\\xc3\\xadfico da lista pelo seu ID\n"
  "uint8 VEHICLE_ROI_LOCATION = 3 # Fixa o apontamento dos sensores para uma coordenada geogr\\xc3\\xa1fica est\\xc3\\xa1tica no espa\\xc3\\xa7o\n"
  "uint8 VEHICLE_ROI_TARGET   = 4 # Habilita rastreamento cont\\xc3\\xadnuo de um alvo din\\xc3\\xa2mico m\\xc3\\xb3vel rastreado pelo sistema\n"
  "uint8 VEHICLE_ROI_ENUM_END = 5\n"
  "\n"
  "# A\\xc3\\xa7\\xc3\\xb5es de atua\\xc3\\xa7\\xc3\\xa3o do subsistema de paraquedas de emerg\\xc3\\xaancia\n"
  "uint8 PARACHUTE_ACTION_DISABLE = 0\n"
  "uint8 PARACHUTE_ACTION_ENABLE  = 1\n"
  "uint8 PARACHUTE_ACTION_RELEASE = 2 # Ejeta fisicamente o paraquedas cortando os motores no processo\n"
  "\n"
  "# Mapeamento de unidades de hardware para o comando de inje\\xc3\\xa7\\xc3\\xa3o de falhas simuladas (VEHICLE_CMD_INJECT_FAILURE)\n"
  "uint8 FAILURE_UNIT_SENSOR_GYRO           = 0\n"
  "uint8 FAILURE_UNIT_SENSOR_ACCEL          = 1\n"
  "uint8 FAILURE_UNIT_SENSOR_MAG            = 2\n"
  "uint8 FAILURE_UNIT_SENSOR_BARO           = 3\n"
  "uint8 FAILURE_UNIT_SENSOR_GPS            = 4\n"
  "uint8 FAILURE_UNIT_SENSOR_OPTICAL_FLOW   = 5\n"
  "uint8 FAILURE_UNIT_SENSOR_VIO            = 6\n"
  "uint8 FAILURE_UNIT_SENSOR_DISTANCE_SENSOR = 7\n"
  "uint8 FAILURE_UNIT_SENSOR_AIRSPEED       = 8\n"
  "uint8 FAILURE_UNIT_SYSTEM_BATTERY        = 100\n"
  "uint8 FAILURE_UNIT_SYSTEM_MOTOR          = 101\n"
  "uint8 FAILURE_UNIT_SYSTEM_SERVO          = 102\n"
  "uint8 FAILURE_UNIT_SYSTEM_AVOIDANCE      = 103\n"
  "uint8 FAILURE_UNIT_SYSTEM_RC_SIGNAL      = 104\n"
  "uint8 FAILURE_UNIT_SYSTEM_MAVLINK_SIGNAL = 105\n"
  "\n"
  "# Tipos de assinatura de falha a serem injetadas no comportamento do componente alvo selecionado\n"
  "uint8 FAILURE_TYPE_OK           = 0 # Retorna o componente ao comportamento operacional normal\n"
  "uint8 FAILURE_TYPE_OFF          = 1 # Simula desligamento completo ou perda total de comunica\\xc3\\xa7\\xc3\\xa3o com o dispositivo\n"
  "uint8 FAILURE_TYPE_STUCK        = 2 # Trava a leitura do sensor no \\xc3\\xbaltimo valor v\\xc3\\xa1lido lido antes da falha\n"
  "uint8 FAILURE_TYPE_GARBAGE      = 3 # Injeta ru\\xc3\\xaddo aleat\\xc3\\xb3rio de alta frequ\\xc3\\xaancia inviabilizando o uso dos dados pelo EKF2\n"
  "uint8 FAILURE_TYPE_WRONG        = 4 # Aplica um offset est\\xc3\\xa1tico constante corrompendo a calibra\\xc3\\xa7\\xc3\\xa3o do sensor\n"
  "uint8 FAILURE_TYPE_SLOW         = 5 # Reduz a taxa de atualiza\\xc3\\xa7\\xc3\\xa3o dr\\xc3\\xa1stica do componente simulando sobrecarga de barramento\n"
  "uint8 FAILURE_TYPE_DELAYED      = 6 # Introduz um atraso temporal fixo na chegada das leituras ao estimador\n"
  "uint8 FAILURE_TYPE_INTERMITTENT = 7 # Alterna o funcionamento aleatoriamente entre operacional e em falha\n"
  "\n"
  "# Tipos de refer\\xc3\\xaancia de velocidade para o comando VEHICLE_CMD_DO_CHANGE_SPEED (Injetado via param1)\n"
  "uint8 SPEED_TYPE_AIRSPEED     = 0 # Velocidade relativa ao ar (Crucial para sustenta\\xc3\\xa7\\xc3\\xa3o aerodin\\xc3\\xa2mica de asas fixas)\n"
  "uint8 SPEED_TYPE_GROUNDSPEED  = 1 # Velocidade real em rela\\xc3\\xa7\\xc3\\xa3o ao solo obtida via GPS/Filtro\n"
  "uint8 SPEED_TYPE_CLIMB_SPEED  = 2 # Velocidade vertical positiva de subida\n"
  "uint8 SPEED_TYPE_DESCEND_SPEED = 3 # Velocidade vertical negativa de descida\n"
  "\n"
  "# Comportamento de orienta\\xc3\\xa7\\xc3\\xa3o do Yaw durante a execu\\xc3\\xa7\\xc3\\xa3o do comando de \\xc3\\xb3rbita (Injetado via param3)\n"
  "uint8 ORBIT_YAW_BEHAVIOUR_HOLD_FRONT_TO_CIRCLE_CENTER = 0 # Mant\\xc3\\xa9m o nariz do drone apontado fixamente para o centro da \\xc3\\xb3rbita\n"
  "uint8 ORBIT_YAW_BEHAVIOUR_HOLD_INITIAL_HEADING        = 1 # Trava a proa no \\xc3\\xa2ngulo que estava no momento do in\\xc3\\xadcio do comando\n"
  "uint8 ORBIT_YAW_BEHAVIOUR_UNCONTROLLED                = 2 # Desativa o controle de guinada autom\\xc3\\xa1tico deixando o Yaw livre\n"
  "uint8 ORBIT_YAW_BEHAVIOUR_HOLD_FRONT_TANGENT_TO_CIRCLE = 3 # Alinha o nariz do drone tangencialmente apontando para a dire\\xc3\\xa7\\xc3\\xa3o do movimento\n"
  "uint8 ORBIT_YAW_BEHAVIOUR_RC_CONTROLLED               = 4 # Permite que o piloto altere o Yaw manualmente via r\\xc3\\xa1dio sem quebrar a trajet\\xc3\\xb3ria\n"
  "uint8 ORBIT_YAW_BEHAVIOUR_UNCHANGED                  = 5 # Mant\\xc3\\xa9m o comportamento de orienta\\xc3\\xa7\\xc3\\xa3o de Yaw configurado anteriormente no sistema\n"
  "\n"
  "# A\\xc3\\xa7\\xc3\\xb5es b\\xc3\\xa1sicas de armamento (Injetado via param1 em VEHICLE_CMD_COMPONENT_ARM_DISARM)\n"
  "int8 ARMING_ACTION_DISARM = 0\n"
  "int8 ARMING_ACTION_ARM    = 1\n"
  "\n"
  "# A\\xc3\\xa7\\xc3\\xb5es de controle de garras f\\xc3\\xadsicas de carga (Injetado via param2 em VEHICLE_CMD_DO_GRIPPER)\n"
  "uint8 GRIPPER_ACTION_RELEASE = 0 # Abre o mecanismo liberando o objeto preso\n"
  "uint8 GRIPPER_ACTION_GRAB    = 1 # Fecha o mecanismo prendendo a carga \\xc3\\xbatil\n"
  "\n"
  "uint8 ORB_QUEUE_LENGTH = 8 # Define o tamanho m\\xc3\\xa1ximo de reten\\xc3\\xa7\\xc3\\xa3o de mensagens n\\xc3\\xa3o processadas na fila uORB\n"
  "\n"
  "# --- DECLARA\\xc3\\x87\\xc3\\x83O DE VARI\\xc3\\x81VEIS DO PAYLOAD REAIS DA MENSAGEM ---\n"
  "float32 param1           # Par\\xc3\\xa2metro gen\\xc3\\xa9rico 1 (Geralmente dados de controle, configura\\xc3\\xa7\\xc3\\xb5es e flags de sub-enums)\n"
  "float32 param2           # Par\\xc3\\xa2metro gen\\xc3\\xa9rico 2 (Geralmente tempos de integra\\xc3\\xa7\\xc3\\xa3o, ganhos secund\\xc3\\xa1rios ou velocidades)\n"
  "float32 param3           # Par\\xc3\\xa2metro gen\\xc3\\xa9rico 3 (Geralmente raios de \\xc3\\xb3rbita, limites din\\xc3\\xa2micos ou dire\\xc3\\xa7\\xc3\\xb5es de giro)\n"
  "float32 param4           # Par\\xc3\\xa2metro gen\\xc3\\xa9rico 4 (Geralmente \\xc3\\xa2ngulos de orienta\\xc3\\xa7\\xc3\\xa3o, atitudes de Yaw e m\\xc3\\xa1scaras de bits)\n"
  "float64 param5           # Par\\xc3\\xa2metro gen\\xc3\\xa9rico 5 - Alta Precis\\xc3\\xa3o (Usado para transporte de coordenadas de Latitude global)\n"
  "float64 param6           # Par\\xc3\\xa2metro gen\\xc3\\xa9rico 6 - Alta Precis\\xc3\\xa3o (Usado para transporte de coordenadas de Longitude global)\n"
  "float32 param7           # Par\\xc3\\xa2metro gen\\xc3\\xa9rico 7 (Usado para transporte de altitudes ou par\\xc3\\xa2metros flutuantes finais)\n"
  "uint32 command           # Identificador Num\\xc3\\xa9rico de Comando Execut\\xc3\\xa1vel (Corresponde aos IDs VEHICLE_CMD_*)\n"
  "uint8 target_system      # Identifica\\xc3\\xa7\\xc3\\xa3o do MAVLink System ID destino do comando\n"
  "uint8 target_component   # Identifica\\xc3\\xa7\\xc3\\xa3o do MAVLink Component ID destino (0 envia em broadcast para todas as placas/perif\\xc3\\xa9ricos)\n"
  "uint8 source_system      # Identifica\\xc3\\xa7\\xc3\\xa3o do MAVLink System ID de quem gerou a mensagem (Ex: ID da Raspberry Pi)\n"
  "uint16 source_component  # Identifica\\xc3\\xa7\\xc3\\xa3o do MAVLink Component ID / Executor de modo de quem originou o envio\n"
  "uint8 confirmation       # Contador de pacotes de confirma\\xc3\\xa7\\xc3\\xa3o (0 para envio inicial, incrementos sequenciais para reenvios cr\\xc3\\xadticos)\n"
  "bool from_external       # Flag de auditoria de seguran\\xc3\\xa7a (Define se a origem \\xc3\\xa9 um link externo MAVLink ou nativa interna)\n"
  "\n"
  "uint16 COMPONENT_MODE_EXECUTOR_START = 1000 # Endere\\xc3\\xa7amento inicial padr\\xc3\\xa3o para executores customizados de modos de voo\n"
  "\n"
  "# TOPICS vehicle_command gimbal_v1_command vehicle_command_mode_executor";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
px4_msgs__msg__VehicleCommand__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {px4_msgs__msg__VehicleCommand__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 24303, 24303},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
px4_msgs__msg__VehicleCommand__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *px4_msgs__msg__VehicleCommand__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
