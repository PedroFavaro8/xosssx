# WinDurango — registro de implementação

## Escopo

Camada de compatibilidade executável para APIs públicas/reimplementadas, com
backends locais de gráficos, áudio, armazenamento e controle. O projeto não
modifica, empacota, assina ou executa imagens do `$SystemUpdate`, firmware,
chaves ou componentes proprietários.

## Estado

- [x] Documentar arquitetura e limites legais/técnicos.
- [x] Evitar sobrescrita de configuração existente em `Config::parse()`.
- [x] Confirmar que o backend atual de controle usa XInput.
- [x] Corrigir ciclo de vida e detecção de controles.
- [x] Implementar registro/remoção dos eventos `GamepadAdded`/`GamepadRemoved`.
- [x] Remover leitura sintética de navegação.
- [x] Adicionar validações estáticas de contrato para entrada e configuração.
- [ ] Executar testes compilados de contrato em runtime.
- [x] Criar um host executável para diagnóstico e carregamento controlado de módulos.
- [ ] Validar build limpa em ambiente com CMake/MSVC.

## Registro

### 2026-09-24

- Criado o documento de arquitetura.
- Corrigido o comportamento destrutivo da configuração.
- Confirmado que a implementação local já possui mapeamento XInput básico.
- Próxima frente: tornar o backend de input determinístico, seguro e testável.
- Implementado registro/remoção de handlers, preservação do estado `gamepad`,
  proteção contra chamadas XInput inválidas e debounce do atalho F9.
- O backend agora retorna uma lista vazia quando XInput não está disponível e
  não cria um controle fictício nem inventa navegação.
- `Config::parse()` agora falha de forma segura quando não recebeu um diretório.
- Criado `WinDurangoHost` com `--version`, `--list-modules`, `--self-test` e
  `--probe`; o host só carrega DLLs fornecidas explicitamente para diagnóstico.
- Registrado o teste CTest `WinDurangoHostSelfTest`.
- A enumeração XInput agora atualiza a cada consulta, preserva instâncias,
  dispara eventos de entrada/saída e retorna o ID correto.
- Removido o efeito colateral de esconder/prender o cursor durante a enumeração;
  o bloqueio do mouse permanece restrito ao modo de mouse lock.
- Corrigido o mapeamento invertido dos gatilhos no fallback de teclado.
- Leituras brutas de gamepad agora recebem timestamp em todas as consultas.
- `--probe` agora aceita somente nomes presentes no manifesto de DLLs de
  compatibilidade, evitando carregamento arbitrário pelo host.
- `--probe` também exige que a DLL esteja no diretório atual, impedindo que o
  host carregue acidentalmente um componente externo com nome permitido.
- Manifesto do host corrigido para usar os nomes efetivos dos artefatos CMake
  (`winrt_x.dll`, `kernelx.dll`, `d3d11_x.dll`, entre outros).
- Incluídos também os artefatos Kinect e `WinDurango.Implementation.WinRT` no
  manifesto de diagnóstico.
- `--self-test` agora rejeita entradas com caminho, extensão incorreta ou nomes
  duplicados ignorando maiúsculas/minúsculas.
- A validação compara opcionalmente o manifesto com `WinDurango-Release` quando
  esse diretório de artefatos existe no workspace.
- A validação agora cruza automaticamente `OUTPUT_NAME` dos CMakeLists com o
  manifesto do host para detectar DLLs novas esquecidas.
- Criado `docs/COMPATIBILITY_SCOPE.md` para impedir que o projeto prometa
  suporte inexistente a jogos, DVDs ou imagens proprietárias.
- O build do `homebrew-xbox` não pôde ser executado: não há .NET SDK instalado
  neste ambiente (`dotnet build` retornou `No .NET SDKs were found`).
- Criado `tools/doctor.ps1` para diagnosticar CMake, MSVC, Ninja, MIDL,
  cppwinrt, .NET SDK e a pasta de artefatos WinRT gerados.
- Documentada a camada `WinDurango.Host` na arquitetura do projeto.
- Interfaces abstratas de armazenamento agora têm destrutores virtuais,
  evitando comportamento indefinido ao liberar implementações via ponteiro base.
- Implementado `Gamepad::GetNavigationReading()` com conversão de D-pad,
  analógico esquerdo, Menu/View e A/B/X/Y para `INavigationReading`.
- `GetRawNavigationReading()` agora usa a mesma conversão, mantendo as duas
  APIs de navegação coerentes.
- Logging protegido por `std::recursive_mutex` durante inicialização, criação
  de códigos de espaço e escrita concorrente.
- A API `Controller` agora registra eventos, retorna IDs reais, cria wrappers
  por ID e expõe a lista de gamepads ordenada sem lançar exceções artificiais.
- `NavigationController` agora fornece tipo, usuário e leituras brutas vazias
  com timestamp, em vez de lançar exceções para operações básicas.
- Criado `tests/validate_project.ps1` para verificar invariantes do host,
  configuração, input e ausência de dependência de imagens do sistema.
- Integrados os checks estáticos e o CTest ao workflow Windows de build.
- Alinhados todos os subprojetos ao CMake mínimo 3.30 da raiz; a validação
  agora rejeita módulos que voltem a exigir CMake 4.x.
- Alinhado também o `CMakePresets.json` ao mínimo 3.30.
- A validação PowerShell agora é registrada automaticamente como teste CTest
  em builds Windows quando PowerShell está disponível.
- Inicialização do núcleo e logging tornados idempotentes e defensivos: diretório
  nulo, arquivo de log nulo e falhas de configuração agora impedem estado parcial.
- Adicionado `WinDurangoHost --capabilities` e documentado o perfil Windows x64
  com 8 GB como alvo mínimo, mantendo GPU/driver como requisitos separados.
- Centralizado o limite de memória do perfil em `PlatformProfile.h`; o host
  agora compara bytes físicos diretamente, sem arredondamento para GiB.
- `doctor.ps1` agora verifica Git e a presença do workflow de publicação no
  GitHub Actions.
- Adicionada a janela Win32 `WinDurangoHost --window`, com shell próprio de
  diagnóstico para validar visualmente o perfil x64/8 GB; ela não carrega
  `$SystemUpdate`, firmware, `.xvd` ou conteúdo proprietário.
- Corrigido o linkage da entrada da janela entre `main.cpp` e `Window.cpp`, e
  incluída uma verificação estática para garantir que a fonte participe do alvo.
- A janela agora consulta a arquitetura e a memória física do host em tempo de
  execução e exibe o resultado do perfil x64/8 GiB, em vez de mostrar valores
  fixos.
- `NavigationController` agora delega as leituras de navegação e brutas ao
  mesmo adaptador XInput do `Gamepad`, removendo a exceção de não implementado
  e evitando leituras vazias.
- `User::Controllers()` agora expõe a enumeração real de controladores, e o
  vínculo `Gamepad::User()` usa o ID de usuário limitado aos quatro slots locais.
- Adicionado supervisor de dashboard próprio: um `.exe` em `apps\\` é iniciado
  como processo principal e `.exe` em `services\\` como auxiliares; há validação
  de diretório/extensão e encerramento dos auxiliares ao fim do dashboard.
- Corrigido o código de saída de `validate_project.ps1` para que um PASS não
  herde falhas de comandos anteriores quando executado pelo `doctor.ps1`.
- Adicionado `--inspect-media` para reconhecer extensões de mídia, aceitar
  `.exe` apenas como diagnóstico e reportar `.xex`/`.xvd` como formatos não
  carregáveis sem ler ou executar seu conteúdo.
- O supervisor agora usa ownership explícito e movimentável para handles de
  processos, evitando cópia acidental e double-close em falhas de inicialização.
- A validação do supervisor agora trata extensões `.exe` sem diferenciar
  maiúsculas/minúsculas, como ocorre no sistema de arquivos do Windows.
- Criado o diretório `apis\\` com ABI C versão 1 e descoberta automática de DLLs
  próprias; o host valida `WinDurangoApiGetInfo`/`WinDurangoApiInitialize` e
  carrega APIs válidas sem manifesto manual.
- Adicionada a DLL-fixture `WinDurangoApiFixture` e o teste CTest correspondente;
  o CI agora pode comprovar a descoberta e inicialização de uma API própria em
  `bin\\apis`.
- Corrigada a saída multi-config da fixture para `bin\\<Config>\\apis`,
  alinhada ao diretório efetivo do `WinDurangoHost` no Visual Studio.
- Criado `docs/API_INVENTORY.md`, separando contratos declarados nos IDLs,
  estado implementado e áreas ainda stub, sem assumir que nomes internos sejam
  APIs públicas ou prometer compatibilidade com jogos comerciais.
- Corrigidos contratos de armazenamento: `File::open()`/`close()` agora
  retornam sucesso corretamente, remoção invalida o handle e cópia de diretório
  não altera o caminho do objeto original.
- O backend de controle agora tenta `xinput1_4`, `xinput1_3` e
  `xinput9_1_0`, descartando DLLs que não expõem o conjunto completo de funções.
- Leituras de gamepad agora toleram chamadas antes da inicialização do núcleo:
  logging e configuração de teclado só acessam `p_wd` quando o ponteiro existe.
- Intensidades de vibração agora são limitadas ao intervalo `0..1` antes da
  conversão para a faixa de 16 bits do XInput.
- Quando o backend XInput fica indisponível, `Gamepad::Gamepads()` agora emite
  os eventos `GamepadRemoved` correspondentes antes de limpar a coleção.
- Adicionado o pacote próprio `.wdapp`: pasta dentro de `apps\\` com `app.exe`
  e APIs opcionais em `apis\\`, iniciado por `--launch-package`.
- A descoberta de APIs do pacote agora ocorre somente depois da validação do
  caminho `.wdapp` dentro de `apps\\`, evitando carregamento fora do escopo.
- Pacotes `.wdapp` agora também descobrem `services\\*.exe` e os executam em
  segundo plano durante a vida de `app.exe`, encerrando-os ao final.
- Adicionado teste CTest com caminho absoluto para a DLL-fixture, cobrindo o
  carregamento explícito de APIs externas via `--load-api`.
- Documentado também no README principal o carregamento explícito de DLLs
  externas por caminho absoluto.
- Alinhado o README principal ao escopo clean-room atual, removendo instruções
  antigas de copiar DLLs de `EmbeddedXvd` e marcando a lista histórica de jogos
  como não validada pelo host atual.
- O carregador de APIs agora normaliza caminhos relativos para caminhos canônicos
  antes de chamar `LoadLibraryExW` e evita inicializar duas vezes a mesma DLL,
  mantendo o suporte a DLLs externas em qualquer diretório permitido.
- Reexecutada a validação estática do projeto: `PASS: WinDurango static project
  checks`.
- Reforçada a validação do carregador: o caminho canônico também é filtrado
  antes do carregamento e a deduplicação agora ignora diferenças de maiúsculas
  e minúsculas, como o sistema de arquivos do Windows.
- O supervisor agora retorna o código de saída do dashboard próprio e reporta
  falhas de espera ou consulta do processo, permitindo que o CI detecte uma
  execução malsucedida.
- Adicionado um fixture próprio de pacote em `tests/PackageFixture`, com
  `app.exe`, serviço auxiliar e teste CTest no Windows para exercitar o fluxo
  `.wdapp` sem executar conteúdo externo ou proprietário.
- O fixture agora inclui automaticamente a DLL de API própria em `apis\`, e o
  teste exige a mensagem de inicialização da API para cobrir o carregamento do
  pacote, além da descoberta do dashboard e do serviço.
- O supervisor agora propaga `WINDURANGO_API_ROOT` ao dashboard e aos serviços
  do pacote, permitindo que o próprio programa localize e carregue explicitamente
  as APIs que usa; o fixture verifica essa propagação.
- O fixture do pacote agora exige uma marca criada pelo serviço auxiliar antes
  de terminar, fazendo o teste CTest comprovar também a inicialização real do
  serviço, não apenas a do dashboard.
- A marca do serviço agora usa um token único por execução, propagado por
  `WINDURANGO_PACKAGE_RUN_TOKEN`, eliminando falsos positivos por arquivos
  antigos em execuções repetidas.
- Corrigida a guarda de plataforma do fixture do dashboard, evitando referências
  a APIs Win32 em builds não-Windows; o contrato do supervisor também declara
  explicitamente `std::wstring`.
- A validação estática passou novamente após a inclusão do fixture.
- Verificação final do estado atual: `tests/validate_project.ps1` passou; build e
  CTest compilados permanecem não executados porque o ambiente não possui
  CMake/MSVC/Ninja.
- Criada `WinDurango.sln` para Visual Studio 2022, com projeto Makefile que
  configura o gerador `Visual Studio 17 2022`, usa vcpkg quando disponível e
  compila o alvo CMake `WinDurango` em `Debug|x64` ou `Release|x64`.
- Corrigidas as instruções antigas do README que citavam Visual Studio 2026;
  agora o fluxo documentado usa Visual Studio 2022, CMake 3.30+ e o perfil x64.
