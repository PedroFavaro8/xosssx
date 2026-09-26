# Perfil de plataforma

O primeiro alvo do WinDurango é um runtime de compatibilidade para Windows
x64 com 8 GB ou mais de memória física. O host não promete que todo hardware
x64 seja suficiente: a GPU, os drivers e o suporte a Direct3D continuam sendo
requisitos independentes.

## Perfil mínimo

- Windows x64;
- 8 GB de RAM física;
- Direct3D 11 ou Direct3D 12 funcional;
- controlador XInput ou teclado configurado;
- espaço para o título e seus dados de teste.

## Perfil recomendado

- Windows x64 atualizado;
- 16 GB de RAM;
- GPU com driver WDDM atual e suporte estável a Direct3D 12;
- SSD;
- controle XInput.

Use `WinDurangoHost --capabilities` para verificar arquitetura e memória. A
checagem é apenas de capacidade do host; não é uma declaração de compatibilidade
com jogos comerciais nem com imagens do sistema Xbox.
