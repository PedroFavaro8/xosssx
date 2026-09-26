# Inventário da superfície de APIs

Este documento lista os contratos declarados no repositório. A presença de um
nome em um IDL não prova que ele seja uma API pública da Microsoft; cada entrada
precisa de uma fonte licenciada ou documentação pública antes de ser tratada
como contrato estável. Nenhum componente de imagem de sistema é carregado para
obter essas declarações.

## Contratos declarados

- `Windows.Xbox.Input.idl` — controles, gamepads, leituras, navegação e eventos.
- `Windows.Xbox.System.idl` — usuários, estado local e informações de áudio.
- `Windows.Xbox.Storage.idl` — armazenamento conectado e contêineres.
- `Windows.Xbox.ApplicationModel.idl` — ciclo de vida e ativação de aplicações.
- `Windows.Xbox.UI.idl` — UI do ambiente e acessibilidade.
- `Windows.Xbox.Media.GameTransportControls.idl` — controles de transporte.
- `Windows.Xbox.Networking.idl` — endereçamento e qualidade de rede.
- `Windows.Xbox.Multiplayer.idl` — sessões, parties e configuração multiplayer.
- `Windows.Xbox.Services.idl` — configuração de serviços Xbox.
- `Windows.Xbox.Chat.idl` — contratos de chat.
- `Windows.Xbox.Speech.Recognition.idl` — reconhecimento de fala.
- `Windows.Xbox.Achievements.idl` — conquistas.
- `Windows.Xbox.Management.Deployment.idl` — implantação e transferência.
- `WinDurango.WinRT.Stub.idl` — tipos auxiliares do projeto.

## Estado atual da implementação

Implementado ou parcialmente exercitado no host local:

- `Input`: enumeração XInput, eventos de conexão, vibração, leituras de
  gamepad/navegação e mapeamento de usuários locais.
- `System.User`: quatro slots locais determinísticos e enumeração de controles.
- `Storage`: contratos básicos de diretório/arquivo e configuração não destrutiva.
- Diagnóstico: perfil x64/8 GiB, janela própria, supervisor de dashboard e
  inspeção de extensão sem execução de formatos proprietários.

Ainda pendente ou apenas stub:

- rede, multiplayer, chat, fala, conquistas e serviços online;
- implantação de pacotes e mídia de console;
- partes extensas de D3D, áudio e ciclo de vida.

Esses contratos não são uma promessa de compatibilidade com jogos comerciais,
DVDs, executáveis de console ou imagens do sistema. A implementação deve usar
fixtures próprios e APIs documentadas, sem copiar código, binários, chaves ou
comportamento interno proprietário.
