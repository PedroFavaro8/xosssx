# Escopo de compatibilidade

## Implementado/testável no projeto

- Camada de APIs WinRT reimplementadas pelo WinDurango.
- Backend de controle XInput, com fallback de teclado.
- Diagnóstico de DLLs próprias através do `WinDurangoHost`.
- Testes de contrato e validação estática sem imagens do sistema.
- Aplicações de teste/homebrew que o usuário possa compilar e assinar
  legitimamente.

## Ainda não implementado

- Execução de jogos comerciais de Xbox One ou Xbox Series.
- Reconhecimento ou execução de DVDs/discos de console.
- Boot ou execução do sistema contido em `$SystemUpdate`.
- Hypervisor, secure boot, chaves, DRM, Xbox Live e serviços proprietários.
- Emulação completa de hardware Xbox One/Series.

O projeto não anuncia compatibilidade com Forza Horizon ou qualquer outro jogo
comercial. O primeiro teste funcional deve ser uma aplicação própria de
diagnóstico/homebrew ou um fixture de compatibilidade distribuído com licença
adequada.
