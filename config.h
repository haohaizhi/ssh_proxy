/*
 * @Author: hongqiang 
 * @Date: 2024-04-09 10:12:53 
 * @Last Modified by:   hongqiang 
 * @Last Modified time: 2024-04-09 10:12:53 
 */

#ifndef LIBSSH_CONFIG_H_
#define LIBSSH_CONFIG_H_


enum ssh_config_opcode_e {
    /* Unknown opcode */
    SOC_UNKNOWN = -3,
    /* Known and not applicable to libssh */
    SOC_NA = -2,
    /* Known but not supported by current libssh version */
    SOC_UNSUPPORTED = -1,
    SOC_HOST,
    SOC_MATCH,
    SOC_HOSTNAME,
    SOC_PORT,
    SOC_USERNAME,
    SOC_IDENTITY,
    SOC_CIPHERS,
    SOC_MACS,
    SOC_COMPRESSION,
    SOC_TIMEOUT,
    SOC_STRICTHOSTKEYCHECK,
    SOC_KNOWNHOSTS,
    SOC_PROXYCOMMAND,
    SOC_PROXYJUMP,
    SOC_GSSAPISERVERIDENTITY,
    SOC_GSSAPICLIENTIDENTITY,
    SOC_GSSAPIDELEGATECREDENTIALS,
    SOC_INCLUDE,
    SOC_BINDADDRESS,
    SOC_GLOBALKNOWNHOSTSFILE,
    SOC_LOGLEVEL,
    SOC_HOSTKEYALGORITHMS,
    SOC_KEXALGORITHMS,
    SOC_GSSAPIAUTHENTICATION,
    SOC_KBDINTERACTIVEAUTHENTICATION,
    SOC_PASSWORDAUTHENTICATION,
    SOC_PUBKEYAUTHENTICATION,
    SOC_PUBKEYACCEPTEDKEYTYPES,
    SOC_REKEYLIMIT,
    SOC_IDENTITYAGENT,
    SOC_IDENTITIESONLY,
    SOC_CONTROLMASTER,
    SOC_CONTROLPATH,
    SOC_CERTIFICATE,

    SOC_MAX /* Keep this one last in the list */
};
#endif /* LIBSSH_CONFIG_H_ */