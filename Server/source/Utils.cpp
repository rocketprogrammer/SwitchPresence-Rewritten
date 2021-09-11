#include "Utils.h"
#include <cstring>

namespace Utils
{
const char *getAppName(u64 programId)
{
    static NsApplicationControlData appControlData;
    size_t appControlDataSize;
    NacpLanguageEntry *languageEntry;

    memset(&appControlData, 0, sizeof(NsApplicationControlData));

    if (R_SUCCEEDED(nsGetApplicationControlData(NsApplicationControlSource_Storage, programId, &appControlData, sizeof(NsApplicationControlData), &appControlDataSize)))
    {
        if (R_SUCCEEDED(nacpGetLanguageEntry(&appControlData.nacp, &languageEntry)))
        {
            if (languageEntry != nullptr)
                return languageEntry->name;
        }
    }

    // These are a part of Super Mario 3D All-Stars.
    if (programId == 72138477119234049) {
        return "Super Mario 64";
    } else if (programId == 72138477119234050) {
        return "Super Mario Sunshine";
    } else if (programId == 72138477119234051) {
        return "Super Mario Galaxy";
    } else {
        // Just display the programId.
        std::string res = "Unknown: ";
        res += std::to_string(programId);

        return res.c_str();
    }
}
} // namespace Utils
