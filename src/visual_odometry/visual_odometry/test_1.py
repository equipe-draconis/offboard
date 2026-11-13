#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
# from px4_msgs import 
from sensor_msgs.msg import Image          # Tipo correto para receber a câmera
# from robot_interfaces.msg import RobotStatus # Sua mensagem customizada
from cv_bridge import CvBridge             # Biblioteca que converte imagem do ROS para OpenCV
import cv2

class DetectNode(Node):
    def __init__(self):
        super().__init__("detect_node")
        
        # Ponte para converter imagens do ROS para OpenCV
        self.bridge = CvBridge()
        
        # 1. Subscriber da Câmera Frontal (Pega os frames brutos do Gazebo)
        self.camera_subscriber_ = self.create_subscription(
            Image, 
            "/camera", 
            self.callback_camera, 
            10
        )
        
        # 2. Publisher de Telemetria Customizada (Envia dados mastigados para a Interface)
        self.status_publisher_ = self.create_publisher(
            RobotStatus, 
            "/robot_telemetry", 
            10
        )
        
        self.get_logger().info("Nó de Percepção [DetectNode] inicializado com sucesso!")

    def callback_camera(self, msg: Image):
        try:
            # Converte a imagem do ROS para o formato do OpenCV (Matriz BGR)
            cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
            
            # --- EXEMPLO DE IDEIA: Processamento de Imagem para a Interface ---
            # Vamos converter para escala de cinza e contar quantos pixels brancos existem 
            # (Pode simular a detecção de uma linha ou um obstáculo na frente)
            gray = cv2.cvtColor(cv_image, cv2.COLOR_BGR2GRAY)
            _, thresh = cv2.threshold(gray, 200, 255, cv2.THRESH_BINARY)
            white_pixels = cv2.countNonZero(thresh)
            
            # Determina o status com base na visão computacional
            current_state = "PISTA_LIVRE"
            if white_pixels > 50000: # Se houver algo muito brilhante/perto
                current_state = "OBSTACULO_DETECTADO"
                
        except Exception as e:
            self.get_logger().error(f"Falha ao converter imagem: {str(e)}")
            return

        # 3. Monta a sua Mensagem Customizada para enviar para a Interface
        telemetry_msg = RobotStatus()
        
        # Preenche o Header padrão do ROS 2
        telemetry_msg.header = msg.header 
        telemetry_msg.robot_name = "meu_robot"
        
        # Alimenta os campos que sua interface vai plotar em gráficos
        telemetry_msg.battery_percentage = 98.5 
        telemetry_msg.current_state = current_state
        
        # Simulando dados de odometria/velocidade calculados
        telemetry_msg.linear_velocity = 0.2
        telemetry_msg.angular_velocity = 0.0
        telemetry_msg.hardware_ok = True

        # Publica o pacote completo. A interface só precisa assinar o "/robot_telemetry"
        self.status_publisher_.publish(telemetry_msg)


def main(args=None):
    rclpy.init(args=args)
    node = DetectNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Desligando o nó de percepção...")
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()