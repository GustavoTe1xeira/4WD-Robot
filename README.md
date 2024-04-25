# Robô Sumô 4WD

## Descrição

Este projeto é um robô sumô simples desenvolvido usando Arduino, um Motor Shield e um sensor ultrassônico. O robô é capaz de se mover, procurar um oponente na arena e reagir quando encontra um oponente, obstáculo ou borda.

## Funcionalidades

- Movimento para frente e para trás
- Procura um oponente na arena
- Reage a obstáculos e bordas da arena

## Materiais Utilizados

- Arduino
- Motor Shield
- Sensor Ultrassônico

## Bibliotecas Necessárias

- AFMotor
- Ultrasonic

## Instalação

1. Clone o repositório: git clone https://github.com/seu_usuario/robo-sumo.git
2. Abra o arquivo robo_sumo.ino com a IDE do Arduino.
3. Faça o upload do código para o seu Arduino.

## Configuração

- Conecte os motores aos canais 1, 2, 3 e 4 do Motor Shield.
- Conecte o sensor ultrassônico aos pinos trigger e echo.
- Conecte os sensores de linha aos pinos sensor1 e sensor2.

## Uso

- Após a instalação e configuração, ligue o robô.
- O robô começará a procurar um oponente na arena.
- Ele se moverá para frente, para trás e girará em busca do oponente.
- Quando encontrar um obstáculo ou borda, o robô reagirá parando ou mudando de direção.
